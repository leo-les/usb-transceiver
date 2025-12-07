module tb_sipo;

logic clk, nRST;
logic shift_enable;
logic serial_in;
logic [7:0] data_out;
logic done;

sipo_shift_register DUT(
    .clk(clk),
    .nRST(nRST),
    .shift_enable(shift_enable);
    .serial_in(serial_in);
    .data_out(data_out);
    .busy(busy)
    .done(done);
)

task shift_bit(input logic b);
    begin 
        serial_in = b;
        shift_enable = 1;
        @(posedge clk);
        #1
        $display("Time=%0t, shifted bit=%0b, data_out=%b, done=%b", $time, b, data_out, done);
    end
endtask

initial begin
    clk = 0;
    nRST = 0;
    shift_enable = 0;
    serial_in = 0;

    @(posedge clk);
    nRST = 1;

    logic[7:0] test_data = 8'b1011_0110;
    $display("Shifting data bits: %b", test_data);
    foreach(test_data[i]) begin
        shift_bit(test_data[i]);   // shifts bit i
    end

    shift_enable = 0;
    $display("Final data_out = %b (expected %b)", data_out, test_data);
    $finish;
end
endmodule