module fsm(
    input logic clk, nRST,
    input logic byte_valid,
    input logic is_sync,
    input logic[3:0] pid,
    input logic pid_valid,
    input logic rx_eop,

    output logic prev_sync,
    output logic load_addr,
    output logic load_endp,
    output logic load_data, // work in progress, determining outputs to rx/tx engines
    output logic packet_done,
    output logic[6:0] addr,
    output logic[3:0] endp,
    output logic[7:0] data
);

    // defines every type of PID (packet identifier)
    typedef enum logic[3:0] {
        IN,
        OUT,
        SETUP,
        SOF,
        DATA0,
        DATA1,
        ACK,
        NAK,
        STALL
    } pid_t;

    // defines every state in the FSM during packet reception
    typedef enum logic[7:0] {
        IDLE, // default state
        SYNC, // packet indicating start
        PID, // packet identifier (IN, OUT, SETUP, DATA0, DATA1, ACK, NAK, STALL)
        FRAME_NUMBER, // frame number for SOF packets
        TOKEN_ADDR, // token address
        TOKEN_ENDP, // token endpoint
        TOKEN_CRC5, // token crc5
        DATA, // data (as many 8-bit signals as needed)
        EOP // end of packet
    } state_t;
    state_t current_state, next_state;

    // combinational logic to determine next state based on current state and inputs
    always_comb begin
        load_addr = 0;
        load_endp = 0;
        load_data = 0;
        packet_done = 0;
        prev_sync = 0;
        next_state = current_state;

        case (current_state)
            IDLE: begin
                if (is_sync) begin
                    next_state = SYNC;
                end
            end

            SYNC: begin
                if (pid_valid) begin
                    next_state = PID;
                end
            end
            
            // determines next state (AKA what the next packet should be) based on PID value
            // resource: https://www.learningaboutelectronics.com/Articles/USB-packets.php
            PID: begin
                prev_sync = 1; // previous state was SYNC, needed for packet_decoder

                if (pid_valid) begin
                    case (pid)
                        4'b1001: begin
                            // in (token packet)
                            next_state = TOKEN_ADDR;
                        end
                        4'b0001: begin
                            // out (token packet)
                            next_state = TOKEN_ADDR;
                        end
                        4'b1101: begin
                            // setup (token packet)
                            next_state = TOKEN_ADDR;
                        end
                        4'b0101: begin
                            // sof (frame number)
                            next_state = FRAME_NUMBER;
                        end
                        4'b0011: begin
                            // data0 (data packet)
                            next_state = DATA;
                        end
                        4'b1011: begin
                            // data1 (data packet)
                            next_state = DATA;
                        end
                        4'b0010: begin
                            // ack (handshake packet)
                        end
                        4'b1010: begin
                            // nak (handshake packet)
                        end
                        4'b1110: begin
                            // stall (handshake packet)
                        end
                    endcase
                end
            end

            FRAME_NUMBER: begin
                next_state = EOP;
            end

            TOKEN_ADDR: begin
                load_addr = 1;
                next_state = TOKEN_ENDP;
            end

            TOKEN_ENDP: begin
                load_endp = 1;
                next_state = TOKEN_CRC5;
            end

            TOKEN_CRC5: begin
                next_state = EOP;
            end

            DATA: begin
                load_data = 1;
                if (rx_eop) begin
                    packet_done = 1;
                    next_state = IDLE;
                end
                else begin
                    next_state = DATA;
                end
            end

            EOP: begin
                packet_done = 1;
                next_state = IDLE;
            end

            default: begin
                next_state = IDLE;
            end
        endcase
    end

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            current_state <= IDLE;
        end
        else begin
            if (byte_valid) begin
                current_state <= next_state;
            end
        end
    end

endmodule