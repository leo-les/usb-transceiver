module nrzi_encoder(
    input logic clk, nRST,
    input logic start_encoding, // enable to start encoding
    input logic curr_bit,
    output logic encoded_bit
);

logic prev_encoded_bit;

always_comb begin
    if (start_encoding == 0) begin
        // encoded bit defaults to 0 when no bits are being sent
        encoded_bit = 0;
    end else begin
        // toggle encoded line if curr_bit = 0, else keep it the same
        encoded_bit = (curr_bit == 0) ? ~prev_encoded_bit : prev_encoded_bit;
    end
end

// trigger block when a rising edge of clk or rst is detected
    always_ff @(posedge clk or negedge nRST) begin
    if (!nRST) begin
        // if reset, set previous encoded bit to 0
        prev_encoded_bit <= 0;
        encoded_bit <= 1; // Idle state 
    end else begin
        // assign encoded bit to the 1 bit register prev_encoded_bit to be used in next call
        prev_encoded_bit <= encoded_bit;
    end
end

endmodule
