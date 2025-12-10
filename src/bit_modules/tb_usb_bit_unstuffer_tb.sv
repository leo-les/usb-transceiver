`default_nettype none
module tb_usb_bit_unstuffer_tb();
reg clk=0;
reg nRST=0;
reg in_bit=0;
reg in_valid=0;
wire  reg out_bit;
wire  reg out_valid;
logic[2:0] one_count;
usb_bit_unstuffer uut (
    .clk          (    clk          ),
    .nRST         (    nRST         ),
    .in_bit       (    in_bit       ),
    .in_valid     (    in_valid     ),
    .out_bit      (    out_bit      ),
    .out_valid    (    out_valid    ),
    .one_count    ( one_count)
);
initial begin    
    nRST = 1;
    #10;
    nRST = 0;
    #10;
    nRST = 1;
    in_valid = 1;
    in_bit = 1;
    #10;
    for(int i = 0; i < 20; i++) begin
        if(i == 6 || i == 13 || i == 12) begin
            in_bit = 0;
        end
        else
            in_bit = 1;
        clk = 1;
        #10;
        clk = 0;
        #10;
    end
end    
initial begin
    $dumpfile("db_tb_usb_bit_unstuffer.vcd");
    $dumpvars(1, usb_bit_unstuffer_tb);
end
endmodule
