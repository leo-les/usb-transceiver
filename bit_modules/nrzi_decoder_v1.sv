`default_nettype none
module nrzi_decoder(
    input logic clk, nRST,
    input logic pulse, // pulse from DPLL
    input logic start_decoding, // high when bits are being received
    input logic curr_encoded_bit,
    output logic decoded_bit
);

    logic prev_encoded_bit;

    always_comb begin
        // if curr_encoded_bit != prev_encoded_bit, then curr_bit = 0 (as per NRZI definition)
        if (curr_encoded_bit == prev_encoded_bit) begin
            decoded_bit = 1; // XNOR logic
        end
        else begin
            decoded_bit = 0;
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            // if reset, set previous encoded bit to 0
            prev_encoded_bit <= 0;
        end
        else begin
            if (pulse) begin
                prev_encoded_bit <= curr_encoded_bit;
            end
        end
    end

endmodule
