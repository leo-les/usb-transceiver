module shift_register (
    input logic clk, nRST,
    input logic enable, // signal from the fsm
    input logic [7:0] data_in,
    output logic serial_out,
    output logic done
);
    logic [7:0] data
    logic [2:0] bit_cnt

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST) begin
            data <= 8'b0;
            bit_cnt <= 3'b0;
        end else if(enable) begin
            data <= data_in; // take the data from the input
            bit_cnt <= 3'b0;
        end else begin
            for(int i = 0; i < 7; i++) begin
                data[i] <= data[i+1]; // move down the bits
            end
            data[7] <= 1'b0; // the first bit is assigned to 0
            bit_cnt <= bit_cnt + 1;
        end
    end

    assign serial_out = data[0];
    if(bit_cnt == 3'b111) begin // check if 8 bits have been counted
        assign done = 1;
    end
endmodule