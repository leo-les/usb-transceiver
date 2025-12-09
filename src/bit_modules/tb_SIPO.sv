module tb_sipo_shift_register;

    logic CLK;
    logic nRST;
    logic shift_enable;
    logic serial_in;
    logic [7:0] data_out;
    logic done;

    logic [7:0] test_data = 8'b10110110;

    sipo_shift_register DUT(
        .CLK(CLK),
        .nRST(nRST),
        .shift_enable(shift_enable),
        .serial_in(serial_in),
        .data_out(data_out),
        .done(done)
    );

    always #5 CLK = ~CLK;

    initial begin
        CLK = 0;
        nRST = 0;
        shift_enable = 0;
        serial_in = 0;

        @(posedge CLK);
        nRST = 1;

        $display("Shifting data bits: %b", test_data);

        shift_enable = 1;
        for (int i = 7; i >= 0; i = i - 1) begin
            serial_in = test_data[i];
            @(posedge CLK);
            $display("Time=%0t, shifted bit=%0b, data_out=%b",
                      $time, test_data[i], data_out);
        end
        shift_enable = 0;

        $display("Final data_out = %b (expected %b), done = %b", data_out, test_data, done);
        $finish;
    end
endmodule
