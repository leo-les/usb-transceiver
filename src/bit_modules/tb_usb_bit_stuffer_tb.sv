module tb_bit_stuffer_tb();
reg clk=0;
reg nRST=1;
reg in_bit=0;
reg en=0;
wire  reg out_bit;
wire  reg out_valid;
usb_bit_stuffer uut (
    .clk          (    clk          ),
    .nRST         (    nRST         ),
    .in_bit       (    in_bit       ),
    .en           (    en           ),
    .out_bit      (    out_bit      ),
    .out_valid    (    out_valid    )
);
initial begin    
#10;
nRST = 0;
#10
nRST = 1;
for(int i = 0; i < 21; i++) begin
    in_bit = 1;
    
    if(i == 10) begin
    in_bit = 0;
    end
    clk = 0;
    en = 1;
    #10;
    clk = 1;
    #10;
    
    
end
    
end    
initial begin
    $dumpfile("db_tb_bit_stuffer.vcd");
    $dumpvars(1, tb_bit_stuffer_tb);
end
endmodule
