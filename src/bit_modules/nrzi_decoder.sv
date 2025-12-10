module nrzi_decoder(
    input logic clk, nRST,
    input logic en, // enable to start decoding
    input logic curr_bit,
    input logic pulse, // pulse from DPLL, sets pulse for rest of modules
    output logic decoded_bit,
    output logic done
);
    logic prev_encoded_bit;
    logic next_decoded_bit;

    always_comb begin
        if (en == 0) begin
            next_decoded_bit = 1; // Idle state
        end
        else begin
            if(curr_bit == prev_encoded_bit) 
                next_decoded_bit = 1;
            else
                next_decoded_bit = 0;
        end
    end
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            prev_encoded_bit <= 0;
            done <= 0;
        end 
        else begin
            done <= 0;

            if (pulse) begin
                prev_encoded_bit <= curr_bit;
                decoded_bit <= next_decoded_bit;
                done <= 1;
            end
        end
    end

endmodule
