`default_nettype none
module usb_transmitter_tb();
reg clk=0;
reg nRST=1;
reg d_plus_in=0;
reg d_minus_in=0;
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
initial begin
    #10;
    nRST = 0;
    #10;
    nRST = 1;
    tx_data = 8'b01111111;
    tx_valid = 1;
    #10;
    clk = 1;
    for(int i = 0; i < 30; i++) begin
        #10;
        clk = 0;
        #10;
        clk = 1;
    end
end    
initial begin
    $dumpfile("db_tb_usb_transceiver.vcd");
    $dumpvars(1, usb_transmitter_tb);
end
endmodule
