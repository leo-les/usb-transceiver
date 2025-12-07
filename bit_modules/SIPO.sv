module sipo_shift_register(
    input logic CLK, nRST,
    input logic shift_enable,
    input logic serial_in,
    output logic[7:0] data_out,
    output logic byte_valid,
    output logic done
);
    logic[7:0] data;
    logic[2:0] bit_cnt;

    always_ff @(posedge CLK, negedge nRST) begin 
        if(!nRST) begin 
            data <= '0;
            bit_cnt <= '0;
            byte_valid <= 1'b0;
            done <= 1'b0;
        end else begin
            byte_valid <= 1'b0;

            if (shift_enable) begin
                logic [7:0] tmp;
                tmp = data;
                for (int i = 7; i > 0; i = i - 1 ) begin //d7 d6 d5 d4 d3 d2 d1 d0
                    data[i] <= tmp[i-1]; 
                end
                data[0] <= serial_in;
                bit_cnt <= bit_cnt + 1;
                if(bit_cnt == 3'd7) begin
                    byte_valid <= 1'b1;
                    done <= 1'b1;
                end
                else byte_valid <= 1'b0;
            end
        end
    end

    assign data_out = data;
endmodule