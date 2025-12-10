`default_nettype none
module nrzi_decoder(
    input logic clk, nRST,
    input logic start_decoding, // enable to start encoding
    input logic curr_bit,
    output logic decoded_bit
);
logic prev_encoded_bit;
logic next_decoded_bit;
always_comb begin
    if (start_decoding == 0) begin
        next_decoded_bit = 1; // Idle state
    end else begin
        if(curr_bit == prev_encoded_bit) 
            next_decoded_bit = 1;
        else
            next_decoded_bit = 0;
    end
end
    always_ff @(posedge clk or negedge nRST) begin
    if (!nRST) begin
        prev_encoded_bit <= 1;
    end else begin
        prev_encoded_bit <= curr_bit;
        decoded_bit <= next_decoded_bit;
    end
end
endmodule
