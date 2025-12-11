`default_nettype none
module usb_transceiver(
    input logic clk, nRST,
    input logic d_plus_in, // input to RX side
    input logic d_minus_in, // input to RX side
    output logic d_plus_out, // output of TX side
    output logic d_minus_out, // output of TX side
    output logic tx_1_rx_0, // 1 means transmitting, 0 means receiving
    output logic[7:0] rx_data, // USB receives this byte from host
    output logic rx_valid,
    output logic rx_eop, // if USB is at end of packet
    output logic rx_error,
    input logic[7:0] tx_data, // USB transmits this byte to host
    input logic tx_valid // if not valid, error occurs
);
    logic pulse;
    logic aligned_bit;
    logic nrzi_decoded_bit;
    logic unstuffed_bit;
    logic is_sync_byte;
    logic [7:0] sipo_raw_byte;
    logic fsm_data_valid;
    logic fsm_error_flag;
    logic rx_active; // -> decoder
    logic decoder_done; // decoder -> unstuffer
    logic unstuffer_done; // unstuffer -> sipo
    logic sipo_done; // sipo -> usb output
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin 
            rx_active <= 0;
        end
        else if (rx_eop) begin 
            rx_active <= 0;
        end
        else if (d_plus_in == 0 && d_minus_in == 1) rx_active <= 1; 
    end
    assign is_sync_byte = (sipo_raw_byte == 8'h80) && sipo_done;
    assign rx_data  = sipo_raw_byte;
    assign rx_valid = sipo_done && fsm_data_valid; 
    assign rx_error = fsm_error_flag;
    rx_fsm u_rx_fsm(
        .clk(clk), .nRST(nRST), 
        .SYNC_Detected(is_sync_byte), // calculated above
        .SYNC(is_sync_byte),
        .Data(sipo_done), // byte is ready
        .EOP_Detected(rx_eop), // from u_eop_detector
        .RXActive(rx_active), // start receiving 1 byte
        .RXValid(sipo_done), // byte is ready
        .RXError(1'b0), // do we need this?
        .data_out_valid(fsm_data_valid), // Tells us if the current byte is payload
        .strip_sync_en(), // not needed
        .strip_eop_en(), // not needed
        .frame_complete(), // not needed
        .error_flag(fsm_error_flag)
    );
    dpll u_dpll(
        .clk(clk), .nRST(nRST), .d_plus(d_plus_in), .d_minus(d_minus_in),
        .aligned_bit(aligned_bit), .pulse(pulse)
    );
    eop_detector u_eop_detector(
        .clk(clk), .d_plus(d_plus_in), .d_minus(d_minus_in),
        .rx_eop(rx_eop)
    );
    nrzi_decoder u_nrzi_decoder(
        .clk(clk), .nRST(nRST), .en(rx_active), .curr_bit(aligned_bit), .pulse(pulse),
        .decoded_bit(nrzi_decoded_bit)
    );
    bit_unstuffer u_bit_unstuffer(
        .clk(clk), .nRST(nRST), .in_bit(nrzi_decoded_bit), .in_valid(1'b1),
        .out_bit(unstuffed_bit), .out_valid(unstuffer_done)
    );
    sipo_shift_register u_sipo(
        .clk(clk), .nRST(nRST), .shift_enable(unstuffer_done), .serial_in(unstuffed_bit),
        .data_out(sipo_raw_byte), .done(sipo_done)
    );
    logic raw_tx_bit;
    logic stuffer_valid;
    logic stuffed_bit;
    logic nrzi_encoded_bit;
    logic tx_done;
    logic [7:0] piso_data;
    logic piso_en;
    logic piso_loading;
    logic piso_busy;
    logic piso_done;
    logic stuffer_done;
    logic nrzi_enable;
    tx_fsm u_tx_fsm(
        .clk(clk), .nRST(nRST), 
        .tx_start(tx_valid),
        .tx_data_in(tx_data), // byte to send
        .piso_busy(piso_busy),
        .piso_done(piso_done),
        .stuffer_done(stuffer_done),
        .tx_done(tx_done),
        .piso_loading(piso_loading), // load byte into piso
        .piso_data(piso_data)
    );
    piso_shift_register u_piso(
        .clk(clk), .nRST(nRST), .shift_enable(stuffer_valid), .data_in(piso_data), .load(piso_loading),
        .serial_out(raw_tx_bit), .busy(piso_busy), .done(piso_done)
    );
    bit_stuffer u_bit_stuffer(
        .clk(clk), .nRST(nRST), .in_bit(raw_tx_bit), .stuff_en(piso_done),
        .out_bit(stuffed_bit), .out_valid(stuffer_valid)
    );
    nrzi_encoder u_nrzi_encoder(
        .clk(clk), .nRST(nRST), .enable(nrzi_enable), .curr_bit(stuffed_bit),
        .encoded_bit(nrzi_encoded_bit)
    );
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            tx_1_rx_0 <= 1'b0; // default: RX
        end
        else begin
            if (tx_valid) tx_1_rx_0 <= 1'b1;
            else if (tx_done || rx_active) tx_1_rx_0 <= 1'b0;
        end
    end
    assign d_plus_out  = tx_1_rx_0 ? nrzi_encoded_bit : 1'b0;
    assign d_minus_out = tx_1_rx_0 ? ~nrzi_encoded_bit : 1'b0;
endmodule
