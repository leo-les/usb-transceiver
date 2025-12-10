`default_nettype none
module nrzi_encoder(
    input logic clk, nRST,
    input logic enable, // enable to start encoding
    input logic curr_bit,
    output logic encoded_bit
);
logic prev_encoded_bit, next_encoded_bit;
always_comb begin
    if (enable == 0) begin
        next_encoded_bit = encoded_bit;
    end else begin
        next_encoded_bit = (curr_bit == 0) ? ~prev_encoded_bit : prev_encoded_bit;
    end
end
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            encoded_bit <= 1; // Idle state 
        end else if(enable) begin
            encoded_bit <= next_encoded_bit;
        end
    end
    always_ff @(negedge clk or negedge nRST) begin
        if (!nRST) begin
            prev_encoded_bit <= 1;
        end else if(enable) begin
            prev_encoded_bit <= encoded_bit;
        end
    end
endmodule
