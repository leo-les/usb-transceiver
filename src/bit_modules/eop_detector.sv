module eop_detector(
    input logic clk,
    input logic d_plus,
    input logic d_minus,
    output logic rx_eop
)

    logic [6:0] se0_counter;
    logic is_se0;

    assign is_se0 = (!d_plus && !d_minus);

    always_ff @(posedge clk) begin
        if (is_se0) begin
            if (se0_counter < 4'd127) begin
                se0_counter <= se0_counter + 1;
            end
        end else begin
            // 48 MHz / 1.5 Mbps = 32 clocks per bit
            // rx_eop is high if is_se0 is high for 2 bits (64 clocks, using 48 for leeway)
            if (se0_counter > 48) begin
                rx_eop <= 1;
            end
            else begin
                rx_eop <= 0;
            end
        end

        se0_counter <= 0;
    end

endmodule