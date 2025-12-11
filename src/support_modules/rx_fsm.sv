`default_nettype none
module rx_fsm (
    input  logic clk, nRST,
    input logic SYNC_Detected,
    input logic SYNC,
    input logic Data,
    input logic EOP_Detected,
    input logic RXActive,
    input logic RXValid,
    input logic RXError,
    output logic data_out_valid,
    output logic strip_sync_en,
    output logic strip_eop_en,
    output logic frame_complete,
    output logic error_flag
);
typedef enum logic [3:0] {
    S_RESET,
    S_RX_WAIT,
    S_STRIP_SYNC,
    S_RX_DATA,
    S_RX_DATA_WAIT,
    S_STRIP_EOP,
    S_ERROR,
    S_ABORT_1,
    S_ABORT_2,
    S_TERMINATE
} rx_state_t;
    rx_state_t current_state, next_state;
        always_ff @(posedge clk or negedge nRST) begin
            if (!nRST) begin
            current_state <= S_RESET; 
        end else begin
            current_state <= next_state;
        end
    end
    always_comb begin
        next_state = current_state; 
        data_out_valid = 1'b0;
        strip_sync_en  = 1'b0;
        strip_eop_en   = 1'b0;
        frame_complete = 1'b0;
        error_flag     = 1'b0;
        case (current_state)
            S_RESET: begin
                next_state = S_RX_WAIT;
            end
            S_RX_WAIT: begin
                if (SYNC_Detected) next_state = S_STRIP_SYNC;
            end
            S_STRIP_SYNC: begin
                if (Data) next_state = S_RX_DATA;
            end
            S_RX_DATA: begin
                data_out_valid = 1'b1;
                if (EOP_Detected) next_state = S_STRIP_EOP;
                else if (!Data && !RXValid) next_state = S_RX_DATA;
                else if (RXError) next_state = S_ERROR;
                else if (Data && RXValid) 
                    next_state = S_TERMINATE;
            end
            S_STRIP_EOP: begin
                strip_eop_en = 1'b1;
                if (!RXActive && RXValid) next_state = S_TERMINATE;
            end
            S_ERROR: begin
                error_flag = 1'b1;
                if (!RXValid && !RXError) next_state = S_ABORT_2;
            end
            S_ABORT_1: begin
                error_flag = 1'b1;
                if (!RXActive && !RXValid && !RXError) next_state = S_ABORT_2;
                else if (!RXActive && RXValid) next_state = S_STRIP_EOP; 
            end
            S_ABORT_2: begin
                error_flag = 1'b1;
                if (!RXActive) next_state = S_TERMINATE; 
                else if (RXValid && RXError) next_state = S_ERROR;
            end
            S_TERMINATE: begin
                frame_complete = 1'b1;
                if (!RXActive) next_state = S_RX_WAIT; 
            end
            default: next_state = S_RESET;
        endcase
    end
endmodule
