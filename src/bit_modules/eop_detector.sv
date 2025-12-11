`default_nettype none
module eop_detector(
    input logic clk,
    input logic d_plus,
    input logic d_minus,
    output logic rx_eop
);
    logic [6:0] se0_counter;
    logic is_se0;
    assign is_se0 = (!d_plus && !d_minus);
    always_ff @(posedge clk) begin
        if (is_se0) begin
            if (se0_counter < 7'd127) begin
                se0_counter <= se0_counter + 1;
            end
        end else begin
            if (se0_counter > 48) begin
                rx_eop <= 1;
            end
            else begin
                rx_eop <= 0;
            end
            se0_counter <= 0;
        end
    end
endmodule