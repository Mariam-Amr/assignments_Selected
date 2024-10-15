#include "uart.h"
#include "uart_msg_handler.h"

static char message_buffer[256];
static int message_index = 0;
static int expected_length = -1;
static tpf_uart_msg_handler_recv_cb app_callback = NULL;

static void uart_received_msg_cb(char received_char) {
    static int state = 0; 

    switch (state) {
        case 0: // Waiting for magic pattern
            if (message_index < 2) {
                if ((message_index == 0 && received_char == 'T') || 
                    (message_index == 1 && received_char == 'W')) {
                    message_buffer[message_index++] = received_char;
                } else {
                    message_index = 0; // Reset if pattern is broken
                }
            }

            if (message_index == 2) {
                state = 1; // Move to reading length
            }
            break;

        case 1: // Reading length
            if (message_index < 4) {
                message_buffer[message_index++] = received_char;
            }

            if (message_index == 4) {
                expected_length = (message_buffer[2] << 8) | message_buffer[3];
                state = 2; // Move to reading message
            }
            break;

        case 2: // Reading message
            if (message_index - 4 < expected_length) {
                message_buffer[message_index++] = received_char;
            }

            if (message_index - 4 == expected_length) {
                // Valid message received
                if (app_callback != NULL) {
                    app_callback(&message_buffer[4], expected_length);
                }
                message_index = 0;
                state = 0; // Reset for next message
            }
            break;
    }
}

void uart_handler_init(char uart_channel_num, tpf_uart_msg_handler_recv_cb pf_uart_msg_handler_recv_cb) {
    uart_init(uart_channel_num, uart_received_msg_cb);
    app_callback = pf_uart_msg_handler_recv_cb;
}

void uart_send_msg(char *msg_buf, int msg_length) {
    uart_send(msg_buf, msg_length);
}
