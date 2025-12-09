module nrzi_encoder(
    input logic clk, nRST,
    input logic pulse, // pulse from DPLL
    input logic start_encoding, // high when bits are being sent
    input logic curr_bit,
    output logic encoded_bit
);

    logic prev_encoded_bit;

    assign encoded_bit = prev_encoded_bit;

    always_ff @(posedge clk or posedge rst) begin
        if (!nRST) begin
            // if reset, set prev_encoded_bit to 0
            prev_encoded_bit <= 0;
        end
        else begin
            if (start_encoding == 0) begin
                // if not encoding, set prev_encoded_bit to 0
                prev_encoded_bit <= 0;
            end
            else if (pulse) begin
                // if curr_bit is 0, encoded bit is the complemet of prev_encoded_bit as per NRZI definition
                prev_encoded_bit <= (curr_bit == 0) ? ~prev_encoded_bit : prev_encoded_bit;
            end
        end
    end

endmodule
