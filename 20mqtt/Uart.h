#include <stdio.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

int set_interface_attribs (int fd, int speed, int parity);
void set_blocking (int fd, int should_block);

