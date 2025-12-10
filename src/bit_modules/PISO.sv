module piso_shift_register(
    input logic clk, nRST,
    input logic shift_enable,
    input logic[7:0] data_in,
    input logic load,
    output logic serial_out,
    output logic busy,
    output logic done
);

    // load: let the register take in the parallel data at the same time -> prevent corruption, having more bits or less bits that needed
    // busy: notify that the register is in the shifting process -> prevent taking the data when the shifting process is still going on
    // shift_enable: tell the register when the bit should be shifted shifted
    // done: done tells when the shifting process already ends

    logic[7:0] data;
    logic[2:0] bit_cnt;
    logic tmp;
    always_ff @(posedge clk, negedge nRST) begin
        if(!nRST) begin
            // set all to 0 if reset
            data <= '0;
            bit_cnt <= '0;
            busy <= 1'b0;
            done <= 1'b0;
            tmp <= 1'b0;
        end 
        else begin
            done <= 1'b0;

            if(load && !busy) begin
                data <= data_in;
                bit_cnt <= '0;
                busy <= 1'b1;
            end 
            else if (busy && shift_enable) begin
                tmp <= data[7];
                for (int i = 7; i > 0; i = i -1 ) begin
                    data[i] <= data[i-1];
                end
                data[0] <= 1'b0;
                if(bit_cnt == 3'd7) begin
                    busy <= 1'b0; // check this
                    done <= 1'b1;
                    bit_cnt <= 3'd0;
                end else begin
                    bit_cnt <= bit_cnt + 1'd1;
                end
            end
        end
    end

    assign serial_out = tmp;
    endmodule