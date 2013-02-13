// 10.Feb.2013
// picmaster@mail.bg

`timescale 1ns / 1ps

module usb_rabbit_top(
    input wire CLK60,           // 60MHz clock
    input wire W2C2,            // RXFn
    output wire W2C1,           // RDn
    output wire W2C3,           // OEn

    input wire W2C4,            // Data7
    input wire W2C5,            // Data6
    input wire W2C6,            // Data5
    input wire W2C7,            // Data4
    input wire W2C8,            // Data3
    input wire W2C9,            // Data2
    input wire W2C10,           // Data1
    input wire W2C11,           // Data0

/*
    input wire PORTB_CLK_I,
    input wire PORTB_RXFn_I,
    output wire PORTB_DATA_O,
    output wire PORTB_RDn_O,
    output wire PORTB_OEn_O*/

    // Debug signals
    //output wire W2C12, // debug clock 60MHz
    output wire W2C13, // debug RXFn
    output wire W2C14, // debug OEn
    output wire W2C15  // Heartbeat LED
);

    wire [7:0] data_in;
    assign data_in = {W2C4, W2C5, W2C6, W2C7, W2C8, W2C9, W2C10, W2C11};

    reg [24:0] cnt;
    assign W2C15 = cnt[24];

    assign W2C13 = W2C2;
    assign W2C14 = W2C3;

    ftdi_read_ctrl u1(.clk_i(CLK60), .rxf_n_i(W2C2), .rd_n_o(W2C1), .oe_n_o(W2C3));

    // Heartbeat counter
    always @ (posedge CLK60)
    begin
        cnt <= cnt + 1;
    end

endmodule
