`default_nettype none
module bit_stuffer (
    input  logic clk,
    input  logic nRST,

    // Input bitstream
    input  logic in_bit,
    input  logic en,

    // Output bitstream (stuffed)
    output logic out_bit,
    output logic out_valid  
);

    typedef enum logic[1:0] {NORMAL, STUFFING, RESET} state_t;
    state_t state, next_state;

    logic [2:0] one_count, next_one_count;
    // Clocked logic
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            state <= RESET;
            one_count <= 0;
        end else begin
            one_count <= next_one_count;
            state <= next_state;

        end
    end
    //Next state logic
    always_comb begin
        next_state = state;
        case(state)
            NORMAL: begin
                if(one_count == 5 && in_bit == 1) 
                    next_state = STUFFING;
                else
                    next_state = NORMAL;
            end
            STUFFING: begin
                next_state = NORMAL;
            end
            RESET: begin
                next_state = NORMAL;
            end
        endcase
    end
    // State-based output logic
    always_comb begin
        out_bit = 0;
        out_valid = 0;
        next_one_count = one_count;
        case (state)

        NORMAL: begin
            if (en) begin
                out_valid = 1;
                out_bit = in_bit;
                if(in_bit == 1)
                    next_one_count = one_count + 1;
                else if(in_bit == 0)
                    next_one_count = 0;
            end
        end

        STUFFING: begin
            out_valid = 1;
            out_bit   = 0;
            next_one_count = 0;
        end
        
        RESET: begin
            out_valid = 0;
            next_one_count = 0;
        end

        endcase
    end
    

endmodule





