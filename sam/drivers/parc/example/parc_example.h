/**
 * \file
 *
 * \brief PARC example.
 *
 * Copyright (c) 2013-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef PARC_EXAMPLE_H_INCLUDED
#define PARC_EXAMPLE_H_INCLUDED

/**
 * \page asfdoc_sam_drivers_parc_example Parallel Capture (PARC) - Example Using GPIO as Stimuli
 *
 * \section asfdoc_sam_drivers_parc_example_purpose Purpose
 * This example demonstrates the data capture function provided by the PARC
 * module.
 *
 *
 * \section asfdoc_sam_drivers_parc_example_requirements Requirements
 *  This example can be used with the following evaluation kits with PARC and PDCA modules:
 *  - SAM4L Xplained Pro
 *  - SAM4L8 Xplained Pro
 *
 *
 * \section asfdoc_sam_drivers_parc_example_description Description
 *
 * In this example the GPIO pins on the same evaluation board act as the signal
 * source which provides the PARC module with data, clock, and EN signals.
 *
 * The GPIO pins should be connected to the PARC pins through the development kit's
 * on-board connectors. These pins can be connected easily by using interconnect
 * wires on the SAM4L Xplained Pro and SAM4L8 Xplained Pro evaluation kits.
 *
 * The connection list on SAM4L Xplained Pro or SAM4L8 Xplained Pro is shown in
 * \ref asfdoc_sam_drivers_parc_example_pin_fig "the figure below".
 *
 * \anchor asfdoc_sam_drivers_parc_example_pin_fig
 * \dot
 * digraph structs {
 *   rankdir=LR;
 *   node [shape=record];
 *   gpio [label=" \
 *         <s0> EXT3-P9 (PIN_PA06)| \
 *         <s1> EXT1-P7 (PIN_PC00)| \
 *         <s2> EXT1-P8 (PIN_PC01)| \
 *         <s3> EXT1-P6 (PIN_PC02)| \
 *         <s4> EXT1-P15(PIN_PC03)| \
 *         <s5> EXT2-P7 (PIN_PC04)| \
 *         <s6> EXT2-P8 (PIN_PC05)| \
 *         <s7> EXT2-P9 (PIN_PC06)| \
 *         <s8> EXT4-P5 (PIN_PC17)| \
 *         <s9> EXT4-P6 (PIN_PC18)"];
 *   parc  [label=" \
 *         <s0> EXT3-P15 (PCCK)| \
 *         <s1> EXT3-P8 (PCDATA0)| \
 *         <s2> EXT3-P10(PCDATA1)| \
 *         <s3> EXT4-P15(PCDATA2)| \
 *         <s4> EXT4-P7 (PCDATA3)| \
 *         <s5> EXT4-P8 (PCDATA4)| \
 *         <s6> EXT4-P10(PCDATA6)| \
 *         <s7> EXT4-P9 (PCDATA7)| \
 *         <s8> EXT4-P18(PCEN1)| \
 *         <s9> EXT4-P17(PCEN2)"];
 *   gpio:s0 -> parc:s0;
 *   gpio:s1 -> parc:s1;
 *   gpio:s2 -> parc:s2;
 *   gpio:s3 -> parc:s3;
 *   gpio:s4 -> parc:s4;
 *   gpio:s5 -> parc:s5;
 *   gpio:s6 -> parc:s6;
 *   gpio:s7 -> parc:s7;
 *   gpio:s8 -> parc:s8;
 *   gpio:s9 -> parc:s9;
 * }
 * \enddot
 *
 * \note The PCDATA5 signal is only connected to the LCD connector (EXT5) which
 * cannot be connected to easily using interconnect wires. In this
 * example PCDATA5 is <i>not required</i> so can be left unconnected.
 *
 *
 * \section asfdoc_sam_drivers_parc_example_files Main Files
 * - parc.c: Parallel Capture driver
 * - parc.h: Parallel Capture driver header file
 * - parc_example.c: Parallel Capture example application
 *
 *
 * \section asfdoc_sam_drivers_parc_example_compilinfo Compilation Information
 * This software is written for GNU GCC and IAR Embedded Workbench&reg;
 * for Atmel&reg;. Other compilers may or may not work.
 *
 *
 * \section asfdoc_sam_drivers_parc_example_usage Usage
 *
 * -# Connect the GPIO pins and PARC port according to the above connection
 * list.
 * -# Build the program and download it into the evaluation kit.
 * -# On the computer, open and configure a terminal application
 *    (e.g., HyperTerminal on Microsoft&reg; Windows&reg;) with these settings:
 *   - 115200 baud
 *   - 8 bits of data
 *   - No parity
 *   - 1 stop bit
 *   - No flow control
 * -# Start the application.
 * -# In the terminal window, the following text should appear:
 * \verbatim
       -- SAM PARC Example --
       -- xxxxxx-xx
       -- Compiled: xxx xx xxxx xx:xx:xx -- \endverbatim
 * -# Select the PARC configuration by inputing 'y' or 'n' when the following
 * information is displayed on the terminal:
 * \verbatim
     Press y to sample the data when both data enable pins are enabled.
     Press n to sample the data, don't care the status of the data enable pins.

     Press y to sample all the data.
     Press n to sample the data only one out of two. \endverbatim
 * -# PARC captures data and sends the captured data to the terminal.
 */

#endif /* PARC_EXAMPLE_H_INCLUDED */
