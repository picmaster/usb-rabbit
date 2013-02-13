// 10.Feb.2013
// picmaster@mail.bg

`timescale 1ns / 10ps

module ftdi_read_ctrl_tb;

    // Inputs
    reg clk;
    reg rxf_n;

    // Outputs
    wire rd_n;
    wire oe_n;

    // Instantiate UUT
    ftdi_read_ctrl uut(
        .clk_i(clk),
        .rxf_n_i(rxf_n),
        .rd_n_o(rd_n),
        .oe_n_o(oe_n)
    );

    initial begin
        // Initialize Inputs
        clk = 0;
        rxf_n = 1;

        // Wait xxx ns for global reset to finish
        #76;
        
        // Add stimulus here
        rxf_n = 0;
        #100 rxf_n = 1;

        #100 rxf_n = 0;
        #100 rxf_n = 1;
    end

    parameter PERIOD = 16.67; // ns

    always begin
        #(PERIOD/2) clk = !clk;
    end

endmodule
