module rx_engine(
    input logic clk, nRST,
    input logic byte_valid,
    input logic load_data,
    input logic[7:0] data_in,
    input logic packet_done,

    output logic last_data_byte,
    output logic[7:0] rx_fifo_data, // work in progress
);

    function automatic logic [15:0] update_crc16(input logic [15:0] crc_in, input logic [7:0] data_in);
        logic [15:0] next_crc;
        logic [7:0] d;
        logic [15:0] c;

        d = data_in;
        c = crc_in;

        // Derived logic for USB CRC16 (Poly: 0x8005)
        next_crc[0] = d[7] ^ d[6] ^ d[5] ^ d[4] ^ d[3] ^ d[2] ^ d[1] ^ d[0] ^ c[8] ^ c[9] ^ c[10] ^ c[11] ^ c[12] ^ c[13] ^ c[14] ^ c[15];
        next_crc[1] = d[7] ^ d[6] ^ d[5] ^ d[4] ^ d[3] ^ d[2] ^ d[1] ^ c[9] ^ c[10] ^ c[11] ^ c[12] ^ c[13] ^ c[14] ^ c[15];
        next_crc[2] = d[1] ^ d[0] ^ c[8] ^ c[9];
        next_crc[3] = d[2] ^ d[1] ^ c[9] ^ c[10];
        next_crc[4] = d[3] ^ d[2] ^ c[10] ^ c[11];
        next_crc[5] = d[4] ^ d[3] ^ c[11] ^ c[12];
        next_crc[6] = d[5] ^ d[4] ^ c[12] ^ c[13];
        next_crc[7] = d[6] ^ d[5] ^ c[13] ^ c[14];
        next_crc[8] = d[7] ^ d[6] ^ c[14] ^ c[15] ^ c[0];
        next_crc[9] = d[7] ^ c[15] ^ c[1];
        next_crc[10] = c[2];
        next_crc[11] = c[3];
        next_crc[12] = c[4];
        next_crc[13] = c[5];
        next_crc[14] = c[6];
        next_crc[15] = d[7] ^ d[6] ^ d[5] ^ d[4] ^ d[3] ^ d[2] ^ d[1] ^ d[0] ^ c[7] ^ c[8] ^ c[9] ^ c[10] ^ c[11] ^ c[12] ^ c[13] ^ c[14] ^ c[15];

        return next_crc;
    endfunction

    function automatic logic [4:0] update_crc5(input logic [4:0] crc_in, input logic [7:0] data_in);
        logic [4:0] next_crc;
        logic [7:0] d;
        logic [4:0] c;

        d = data_in; // LSB first
        c = crc_in;

        // Derived logic for USB CRC5 (Poly: 0x05)
        next_crc[0] = d[7] ^ d[6] ^ d[5] ^ d[3] ^ d[0] ^ c[0] ^ c[3] ^ c[4];
        next_crc[1] = d[7] ^ d[6] ^ d[4] ^ d[1] ^ c[0] ^ c[1] ^ c[4];
        next_crc[2] = d[7] ^ d[5] ^ d[2] ^ d[0] ^ c[0] ^ c[1] ^ c[2] ^ c[3] ^ c[4];
        next_crc[3] = d[6] ^ d[3] ^ d[1] ^ c[1] ^ c[2] ^ c[3];
        next_crc[4] = d[5] ^ d[2] ^ d[0] ^ c[2] ^ c[3] ^ c[4];

        return next_crc;
    endfunction

    logic [15:0] crc16_reg;
    crc16_reg = 0xFFFF;
    fifo = {};

    always_ff @(posedge clk, negedge nRST) begin
        if(!nRST) begin
            crc16_reg <= 0xFFFF;
            packet_done <= 0;
            last_data_byte <= 0;
        end
        else begin
            // token 1, 2
            // 2 bit delay pipeline 
        end
    end