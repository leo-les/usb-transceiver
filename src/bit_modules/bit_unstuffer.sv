`default_nettype none
module bit_unstuffer (
    input  logic clk,
    input  logic nRST,
    input  logic in_bit,    // input stuffed bitstream
    input  logic in_valid,
    output logic out_bit,   // output unstuffed stream
    output logic out_valid,
    output logic[2:0] one_count
);
    logic       drop_next;  
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            one_count <= 3'd0;
            drop_next <= 1'b0;
            out_bit   <= 1'b0;
            out_valid <= 1'b0;
        end else begin
            out_valid <= 1'b0; 
            if (in_valid) begin
                if (drop_next) begin
                    drop_next <= 1'b0;
                    one_count <= 3'd0;   // stuffed bit always resets run
                end else begin
                    out_bit   <= in_bit;
                    out_valid <= 1'b1;
                    if (in_bit == 1'b1)
                        one_count <= one_count + 3'd1;
                    else
                        one_count <= 3'd0;
                    if (one_count == 3'd5 && in_bit == 1'b1)
                        drop_next <= 1'b1;
                end
            end
        end
    end
endmodule
