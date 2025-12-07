module bit_unstuffer(
    input logic in_bit, clk, nRST, en
    output logic out_bit, out_valid
);


  always_ff @(posedge clk, negedge nRST) begin

  end

endmodule
