module tx_fsm (
    // System Ports
    input  logic clk, nRST

    // FSM Inputs
    input  logicTXValid,
    input  logic TXReady,
    input  logic TX_Hold_Reg_Empty,
    input  logic TX_Hold_Reg_Full,
    input  logic EOP_not_done,
    
    // FSM Outputs
    output logic send_sync_en,
    output logic data_load_en,
    output logic  send_eop_en
);

// State definitions
typedef enum logic [2:0] { 
    TX_S_RESET,
    TX_S_WAIT,
    TX_S_SEND_SYNC,
    TX_S_DATA_LOAD,
    TX_S_DATA_WAIT,
    TX_S_SEND_EOP
} tx_state_t;

tx_state_t tx_current_state, tx_next_state;

// Sequential Logic
always_ff @(posedge clk or posedge Reset) begin
    if (Reset) begin
        tx_current_state <= TX_S_RESET; 
    end else begin
        tx_current_state <= tx_next_state;
    end
end

// Combinational Logic
always_comb begin
    tx_next_state = tx_current_state; 
    send_sync_en  = 1'b0;
    data_load_en  = 1'b0;
    send_eop_en   = 1'b0;
    
    case (tx_current_state)
        
        TX_S_RESET: begin
            if (!Reset) begin
                tx_next_state = TX_S_WAIT;
            end
        end
        
        TX_S_WAIT: begin
            // Self-loop: !TXValid
            if (TXValid) begin
                tx_next_state = TX_S_SEND_SYNC;
            end
        end
        
        TX_S_SEND_SYNC: begin
            send_sync_en = 1'b1;
            tx_next_state = TX_S_DATA_LOAD; // Unconditional transition
        end
        
        TX_S_DATA_LOAD: begin
            data_load_en = 1'b1;
            
            if (TX_Hold_Reg_Empty) begin // Frame complete
                tx_next_state = TX_S_SEND_EOP;
            end
            else if (TX_Hold_Reg_Full) begin // Buffer full, must pause
                tx_next_state = TX_S_DATA_WAIT;
            end
            else if (!TXValid) begin // Abort/pause due to data not ready
                tx_next_state = TX_S_WAIT;
            end
            // Self-loop: stay in TX_S_DATA_LOAD if TXReady, not full, and not empty
            // This self-loop is implicitly handled by the default tx_next_state = tx_current_state;
        end
        
        TX_S_DATA_WAIT: begin
            // Self-loop: TX Hold Reg Full
            if (TX_Hold_Reg_Empty) begin // Buffer clear, resume loading
                tx_next_state = TX_S_DATA_LOAD;
            end
        end
        
        TX_S_SEND_EOP: begin
            send_eop_en = 1'b1;
            
            // Self-loop: EOP not done
            if (EOP_not_done) begin
                tx_next_state = TX_S_SEND_EOP;
            end
            else begin // EOP done
                tx_next_state = TX_S_WAIT;
            end
        end
        
        default: begin
            tx_next_state = TX_S_RESET;
        end
        
    endcase
end

endmodule