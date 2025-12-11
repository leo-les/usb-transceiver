`default_nettype none
module nrzi_decoder(
    input logic clk, nRST,
    input logic en, // enable to start encoding
    input logic curr_bit,
    input logic pulse,
    output logic decoded_bit
);
    logic prev_encoded_bit;

        always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            prev_encoded_bit <= 1;
            decoded_bit <= 1;
        end else if(en) begin
            if (curr_bit == prev_encoded_bit)
                decoded_bit <= 1;
            else
                decoded_bit <= 0;
                
            prev_encoded_bit <= curr_bit;
        end
        else if(!en) begin
            decoded_bit <= 1;
            prev_encoded_bit <= 1;
        end
        
    end
endmodule
