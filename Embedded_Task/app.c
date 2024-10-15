#include "uart_msg_handler.h"
#include "lcd.h"
#include "app.h"

static void print_msg_cb(char *msg_buf, int msg_length) {
    log("data_length = %d.\n", msg_length);
    log("data =\n");

    int print_counter = 0;

    while (print_counter < msg_length) {
        printf("%02hhx ", msg_buf[print_counter]);
        print_counter++;

        if (print_counter % 16 == 0) {
            log("\n");
        }
    }
    log("\n");
}

static void app_init() {
    uart_handler_init(1, print_msg_cb); // Initialize UART with channel 1 and set callback
}

static void main() {
    app_init();
    while (1);
}
