# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\VM_share\MCU_PSoC_FPGA\WOTAN\WOTAN.cydsn\WOTAN.cyprj
# Date: Sun, 26 Nov 2017 15:25:46 GMT
#set_units -time ns
create_clock -name {CyBUS_CLK(routed)} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/clk_bus}]]
create_clock -name {CyXTAL} -period 166.66666666666666 -waveform {0 83.3333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyPLL_OUT} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 13.888888888888888 -waveform {0 6.94444444444444} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_generated_clock -name {clkADC} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {clkADC(fixed-function)} -period 55.55555555555555 -waveform {0 27.7777777777778} [get_pins {ClockBlock/aclk_glb_ff_0}]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 79 157} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for D:\VM_share\MCU_PSoC_FPGA\WOTAN\WOTAN.cydsn\TopDesign\TopDesign.cysch
# Project: D:\VM_share\MCU_PSoC_FPGA\WOTAN\WOTAN.cydsn\WOTAN.cyprj
# Date: Sun, 26 Nov 2017 15:25:33 GMT
