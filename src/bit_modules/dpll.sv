`default_nettype none
module dpll(
    input logic clk,
    input logic nRST,        // Added Reset
    input logic d_plus,
    input logic d_minus,     // Kept for consistency, though unused in simple edge detect
    output logic aligned_bit,
    output logic pulse
);
    logic [1:0] counter;
    logic d_plus_old;
    logic edge_detected;
    always_comb begin
        edge_detected = (d_plus != d_plus_old);
    end
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            counter <= 0;
            d_plus_old <= 0;
            aligned_bit <= 0;
            pulse <= 0;
        end 
        else begin
            d_plus_old <= d_plus;
            if (edge_detected) begin
                counter <= 0;
                pulse <= 0; // Clear pulse if we re-sync
            end 
            else begin
                counter <= counter + 1;
                if (counter == 2) begin
                    aligned_bit <= d_plus;
                    pulse <= 1; // Sample Now
                end 
                else begin
                    pulse <= 0;
                end
            end
        end
    end
endmodule