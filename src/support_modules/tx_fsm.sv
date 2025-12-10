module tx_fsm (
    input  logic clk, nRST,
    output logic tx_done,

    // Tx control
    input  logic tx_start,
    input  logic [7:0] tx_data_in,

    // PISO interface
    input  logic piso_busy,
    input  logic piso_done,
    output logic piso_loading,
    output logic [7:0] piso_data,

    // Bit stuffer
    input  logic stuffer_done,
);

typedef enum logic [2:0] {
    TX_S_RESET,
    TX_S_WAIT,
    TX_S_SEND_SYNC,
    TX_S_DATA_LOAD,
    TX_S_DATA_WAIT,
    TX_S_SEND_EOP
} tx_state_t;

tx_state_t state, next_state;

localparam [7:0] SYNC_BYTE = 8'b00000001;   // USB SYNC LSB first

always_ff @(posedge clk or negedge nRST) begin
    if (!nRST)
        state <= TX_S_RESET;
    else
        state <= next_state;
end

always_comb begin
    // Default outputs
    piso_loading    = 0;
    piso_data       = 8'h00;
    tx_done         = 0;

    next_state = state;

    case (state)

    TX_S_RESET:
        next_state = TX_S_WAIT;

    TX_S_WAIT:
        if (tx_start)
            next_state = TX_S_SEND_SYNC;

    TX_S_SEND_SYNC: begin
        piso_data    = SYNC_BYTE;
        piso_loading = 1;

        if (!piso_busy && piso_done)
            next_state = TX_S_DATA_LOAD;
    end

    TX_S_DATA_LOAD: begin
        piso_data    = tx_data_in;
        piso_loading = 1;
        next_state = TX_S_DATA_WAIT;
    end

    TX_S_DATA_WAIT: begin

        if (piso_done)
            next_state = TX_S_SEND_EOP;
    end

    TX_S_SEND_EOP: begin
        tx_done = 1;
        next_state = TX_S_WAIT;
    end

    default:
        next_state = TX_S_RESET;

    endcase
end

endmodule