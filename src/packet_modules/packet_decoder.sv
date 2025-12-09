module packet_decoder(
    input logic clk, nRST,
    input logic byte_valid,
    input logic[7:0] data_in,
    input logic prev_sync, // previous state in fsm was SYNC
    output logic is_sync,
    output logic[3:0] pid,
    output logic pid_valid
);

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            pid <= 4'b0000;
            pid_valid <= 0;
            is_sync <= 0;
        end
        else begin
            pid <= 4'b0000;
            pid_valid <= 0;
            is_sync <= 0;

            if (byte_valid) begin
                // if SYNC signal detected, then set is_sync high -> used by FSM
                if (data_in == 8'b10101010) begin // double check wit SIPO
                    is_sync <= 1;
                end 

                if (prev_sync && data_in[3:0] == ~data_in[7:4]) begin
                    pid <= data_in[3:0]; // 4-bit PID value -> used by FSM
                    pid_valid <= 1;
                end
            end
        end
    end

endmodule