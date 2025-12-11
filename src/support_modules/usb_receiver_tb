`default_nettype none
module usb_receiver_tb();
reg clk=0;
reg nRST=1;
reg d_plus_in;
reg d_minus_in;
reg  [7:0] tx_data=0;
reg tx_valid=0;
wire d_plus_out;
wire d_minus_out;
wire tx_1_rx_0;
wire  [7:0] rx_data;
wire rx_valid;
wire rx_eop;
wire rx_error;
logic transmitting;
usb_transceiver uut (
    .clk            (    clk            ),
    .nRST           (    nRST           ),
    .d_plus_in      (    d_plus_in      ),
    .d_minus_in     (    d_minus_in     ),
    .tx_data        (    tx_data        ),
    .tx_valid       (    tx_valid       ),
    .d_plus_out     (    d_plus_out     ),
    .d_minus_out    (    d_minus_out    ),
    .tx_1_rx_0      (    tx_1_rx_0      ),
    .rx_data        (    rx_data        ),
    .rx_valid       (    rx_valid       ),
    .rx_eop         (    rx_eop         ),
    .rx_error       (    rx_error       ),
    .transmitting(transmitting)
);
logic [7:0] transmit_data = 8'b10101010;
assign d_minus_in = ~d_plus_in;
initial begin
    d_plus_in = 1;
    #10;
    nRST = 0;
    #10;
    nRST = 1;
    #10;
    clk = 1;
    d_plus_in = 0;
    for(int i = 0; i < 30; i++) begin
        #10;
        d_plus_in = ~d_plus_in;
        clk = 0;
        #10;
        clk = 1;
    end
end    
initial begin
    $dumpfile("db_tb_usb_transceiver.vcd");
    $dumpvars(1, usb_receiver_tb);
end
endmodule
