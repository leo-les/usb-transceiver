module nrzi_decoder(
    input logic clk, nRST,
    input logic start_decoding, // enable to start encoding
    input logic curr_bit,
    output logic decoded_bit
);

logic prev_encoded_bit;

always_comb begin
    if (start_decoding == 0) begin
        // decoded bit should be?
        decoded_bit = 1; // Idle state
    end else begin
        // if current bit = 1, 
        if(curr_bit == prev_encoded_bit) 
            decoded_bit = 1;
        else
            decoded_bit = 0;
    end
end

// trigger block when a rising edge of clk or rst is detected
    always_ff @(posedge clk or negedge nRST) begin
    if (!nRST) begin
        // if reset, set previous encoded bit to 0
        prev_encoded_bit <= 0;
        decoded_bit <= 1; // Idle state
    end else begin
        // assign encoded bit to the 1 bit register prev_encoded_bit to be used in next call
        prev_encoded_bit <= curr_bit;
    end
end

endmodule
