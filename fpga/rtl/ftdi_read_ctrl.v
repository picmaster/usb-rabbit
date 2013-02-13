// 10.Feb.2013
// picmaster@mail.bg

`timescale 1ns / 1ps

module ftdi_read_ctrl(
    input wire clk_i,
    input wire rxf_n_i,
    output wire rd_n_o,
    output wire oe_n_o
);

    reg q1, q2, q3, q4;

    assign oe_n_o = q2;
    assign rd_n_o = q2 | q4;

    initial begin
        q1 = 0;
        q2 = 0;
        q3 = 0;
        q4 = 0;
    end

    always @ (negedge clk_i)
    begin
        q1 <= rxf_n_i;
        q3 <= q2;
    end

    always @ (posedge clk_i)
    begin
        q2 <= q1;
        q4 <= q3;
    end

endmodule
