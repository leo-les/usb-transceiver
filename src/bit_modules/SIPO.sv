`default_nettype none
module sipo_shift_register(
    input logic clk, nRST,
    input logic shift_enable,
    input logic serial_in,
    output logic[7:0] data_out,
    output logic done
);
    logic[7:0] data;
    logic[2:0] bit_cnt;
    always_ff @(posedge clk, negedge nRST) begin 
        if(!nRST) begin 
            data <= '0;
            bit_cnt <= '0;
            done <= 1'b0;
        end else begin
            done <= 1'b0;
            if (shift_enable) begin
                for (int i = 7; i > 0; i = i - 1 ) begin //d7 d6 d5 d4 d3 d2 d1 d0
                    data[i] <= data[i-1]; 
                end
                data[0] <= serial_in;
                if(bit_cnt == 3'd7) begin
                    done <= 1'b1;
                    bit_cnt <= 3'd0;
                end begin
                    bit_cnt <= bit_cnt + 3'd1;
                end
            end
        end
    end
    assign data_out = data;
endmodule