module nrzi(
    input logic clk,
    input logic rst,
    input logic curr_bit,
    output logic encoded_bit
);

logic prev_encoded_bit;

always_comb begin
    // toggle encoded line if curr_bit = 0
    encoded_bit = (curr_bit == 0) ? ~prev_encoded_bit : prev_encoded_bit;
end

// trigger block when a rising edge of clk or rst is detected
always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        // reset to 0 for previous bit
        prev_encoded_bit <= 0;
    end else begin
        // assign encoded bit to the 1 bit register prev_bit to be used in next call
        prev_encoded_bit <= encoded_bit;
    end
end

endmodule