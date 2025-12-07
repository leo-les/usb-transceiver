module tb_piso_shift_register;

    logic clk, nRST;
    logic shift_enable;
    logic[7:0] data_in;
    logic load;
    logic serial_out;
    logic busy;
    logic done;

    piso_shift_register DUT(
        .clk(clk),
        .nRST(nRST),
        .shift_enable(shift_enable)
        .data_in(data_in),
        .load(load),
        .serial_out(serial_out),
        .busy(busy),
        .done(done)
    );

    task shift_one_bit;
        begin
            shift_enable = 1;
            @(posedge clk);
            $display("Time=%0t, serial_out=%b, data=%b", $time, serial_out, DUT.data);
        end
    endtask

    initial begin
        clk = 0;
        nRST = 0;
        shift_enable = 0;
        load = 0;
        data_in = 8'h00;

        @(posedge clk);
        nRST = 1;

        data_in = 8'b1011_0111;
        $display("Loading data: %b", data_in);
        
        load = 1;
        @(posedge clk);
        load = 0;
        @(posedge clk);

        for (int i = 0; i < 8; i++) begin
            shift_one_bit();
        end

        shift_enable = 0;
        @(posedge clk);
        $display("Shift complete. done=%b, busy=%b", done, busy);
        $finish
    end
    endmodules