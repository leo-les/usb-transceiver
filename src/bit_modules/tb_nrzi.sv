module tb_nrzi.sv;

    logic clk, nRST;
    logic curr_bit;
    logic encoded_bit;

    nrzi DUT(
        .clk(clk),
        .nRST(nRST),
        .curr_bit(curr_bit),
        .encoded_bit(encoded_bit)
    )

    task send_signal(input logic input_bit);
        curr_bit = input_bit;
        @(posedge clk);
        $display("Input Bit: %0b, Encoded Bit: %0b", curr_bit, encoded_bit);
    endtask

    initial begin
        clk = 0;
        nRST = 0;
        curr_bit = 0;

        #5 nRST = 1;

        send_signal(1);
        send_signal(0);
        send_signal(0);
        send_signal(1);
        send_signal(1);
        send_signal(0);
        send_signal(1);
        send_signal(0);

        #10 $finish;
    end