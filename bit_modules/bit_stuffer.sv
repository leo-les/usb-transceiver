module usb_bit_stuffer (
    input  logic clk,
    input  logic nRST,

    // Input bitstream
    input  logic in_bit,
    input  logic en,

    // Output bitstream (stuffed)
    output logic out_bit,
    output logic out_valid  
);

    typedef enum logic {NORMAL, STUFFING} state_t;
    state_t state, next_state;

    logic [2:0] one_count, next_one_count;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            one_count <= '0;
            state     <= NORMAL;
            out_bit   <= 0;
            out_valid <= 0;
        end else begin
            one_count <= next_one_count;
            state <= next_state;

        end
    end
      
    always_comb begin
        case(state)
            NORMAL: begin
                if(next_one_count == 6) 
                    next_state = STUFFING;
                else
                    next_state = NORMAL;
            end
            STUFFING: begin
                next_state = NORMAL;
            end
        endcase
    end
    
    always_comb begin
        out_bit = 0;
        out_valid = 0;
        
        case (state)

        NORMAL: begin
            if (en) begin
                out_valid = 1;
                out_bit = in_bit;
                if(in_bit == 1)
                    next_one_count = one_count + 1;
            end
        end

        STUFFING: begin
            out_valid = 0;
            out_bit   = 0;
            next_one_count = 0;
        end

        endcase
    end
    

endmodule


