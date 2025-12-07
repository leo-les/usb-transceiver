module nrzi_decoder(
    input logic clk, nRST,
    input logic start_encoding, // enable to start encoding
    input logic curr_bit,
    output logic decoded_bit
);

logic prev_decoded_bit;

always_comb begin
    if (start_encoding == 0) begin
        // decoded bit should be?
        decoded_bit = 0;
    end else begin
        // 
        decoded_bit = 
    end
end

// trigger block when a rising edge of clk or rst is detected
always_ff @(posedge clk or posedge rst) begin
    if (!nRST) begin
        // if reset, set previous encoded bit to 0
        prev_encoded_bit <= 0;
    end else begin
        // assign encoded bit to the 1 bit register prev_encoded_bit to be used in next call
        prev_decoded_bit <= decoded_bit;
    end
end

endmodule