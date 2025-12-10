module usb_transceiver(
    input logic clk, nRST,
    input logic d_plus_in, // input to RX side
    input logic d_minus_in, // input to RX side

    output logic d_plus_out, // output of TX side
    output logic d_minus_out, // output of TX side
    output logic tx_1_rx_0 // 1 means transmitting, 0 means receiving

    // perspective of USB transceiver
    output logic[7:0] rx_data, // USB receives this byte from host
    output logic rx_valid, // sipo_done
    output logic rx_eop, // if USB is at end of packet

    input logic[7:0] tx_data // USB transmits this byte to host
    input logic tx_valid // if not valid, error occurs
);

    // RX connector signals (between modules)
    logic pulse;
    logic aligned_bit;
    logic nrzi_decoded_bit;
    logic unstuffed_bit;

    // RX FSM signals (module <-> rx_fsm)
    logic enable_decoder;
    logic decoder_done;
    logic enable_unstuffer;
    logic unstuffer_done;
    logic enable_sipo;

    dpll u_dpll(
        .clk(clk), .d_plus(d_plus_in), .d_minus(d_minus_in),
        .aligned_bit(aligned_bit), .pulse(pulse)
    );

    eop_detector u_eop_detector(
        .clk(clk), .d_plus(d_plus_in), .d_minus(d_minus_in), .pulse(pulse),
        .rx_eop(rx_eop)
    );

    nrzi_decoder u_nrzi_decoder(
        .clk(clk), .nRST(nRST), .en(enable_decoder), .curr_bit(aligned_bit), .pulse(pulse),
        .decoded_bit(nrzi_decoded_bit), .done(decoder_done)
    );

    usb_bit_unstuffer u_usb_bit_unstuffer(
        .clk(clk), .nRST(nRST), .in_bit(nrzi_decoded_bit), .in_valid(enable_unstuffer),
        .out_bit(unstuffed_bit), .out_valid(unstuffer_done)
    );

    sipo_shift_register u_sipo(
        .clk(clk), .nRST(nRST), .shift_enable(enable_sipo), .serial_in(unstuffed_bit),
        .data_out(rx_data), .done(rx_valid) // sipo_done
    );

    rx_fsm u_rx_fsm(
        // TODO: link rx fsm signals
    );

    // TX connector signals (between modules)
    logic raw_tx_bit;
    logic stuffed_bit;
    logic nrzi_encoded_bit;

    // TX FSM signals (module <-> tx_fsm)
    logic enable_piso;
    logic piso_done;
    logic enable_stuffer;
    logic stuffer_done;
    logic enable_encoder;

    piso_shift_register u_piso(
        .clk(clk), .nRST(nRST), .shift_enable(enable_piso), .data_in(tx_data), .done(rx_valid)
        .serial_out(raw_tx_bit), .done(piso_done)
    );

    usb_bit_stuffer u_usb_bit_stuffer(
        .clk(clk), .nRST(nRST), .in_bit(raw_tx_bit), .en(enable_stuffer),
        .out_bit(stuffed_bit), .out_valid(stuffer_done)
    );

    nrzi_encoder u_nrzi_encoder(
        .clk(clk), .nRST(nRST), .en(enable_encoder), .curr_bit(stuffed_bit),
        .encoded_bit(nrzi_encoded_bit)
    );

    tx_fsm u_tx_fsm(
        // TODO: link tx fsm signals
    );

    assign d_plus_out  = tx_1_rx_0 ? nrzi_encoded_bit : 1'b0;
    assign d_minus_out = tx_1_rx_0 ? ~nrzi_encoded_bit : 1'b0;

endmodule