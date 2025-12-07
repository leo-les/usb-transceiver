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
    state_t state;

    logic [2:0] one_count;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            one_count <= '0;
            state     <= NORMAL;
            out_bit   <= 0;
            out_valid <= 0;
        end else begin
            if(in_bit == 1)
                one_count = one_count + 1;
            state <= next_state;

        end
    end
      
    
    always_comb begin
        out_bit = 0;
        case (state)

        NORMAL: begin
            if (en) begin
                if(one_count == 5 && in_bit == 1) 
                    next_state = STUFFING;
                else
                    next_state = NORMAL
                out_valid = 1;
                out_bit = in_bit;
            end
        end

        STUFFING: begin
            out_valid = 0;
            out_bit   = 0;
            one_count = 0;
            next_state = NORMAL;
        end

        endcase
    end
    

endmodule
