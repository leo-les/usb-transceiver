module dpll( // digital phase locked loop
    input logic clk, // 4x oversampling 48 mHz clock
    input logic d_plus, // async input
    input logic d_minus, // async input
    output logic aligned_bit, // aligned bit value
    output logic pulse // pulse indicating aligned bit is valid
)

    logic [1:0] counter;
    logic d_plus_old;
    logic edge_detected;

    assign edge_detected = d_plus != d_plus_old;

    always_ff @(posedge clk) begin
        d_plus_old <= d_plus;

        if (edge_detected) begin
            counter <= 0;
        end
        else begin
            counter <= counter + 1;
        end

        if (counter == 2) begin
            aligned bit <= d_plus
            pulse <= 1; // on this pulse, aligned bit can be sampled
        end
        else begin
            pulse <= 0;
        end
    end

endmodule