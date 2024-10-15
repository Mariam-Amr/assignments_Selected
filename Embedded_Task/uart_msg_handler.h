#ifndef UART_MSG_HANDLER_H
#define UART_MSG_HANDLER_H

typedef void (*tpf_uart_msg_handler_recv_cb)(char *msg_buf, int msg_length);

void uart_received_msg_cb(char received_char);

#endif 
