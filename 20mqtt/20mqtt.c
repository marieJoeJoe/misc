
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include "Uart.h"


int main(int argc, char *argv[])
{

  char *portname = "/dev/ttyUSB3";

  char buf [100];

  int n = -1;

  memset(buf,'\0',100);


  int fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);

  if (fd < 0)
  {
        printf("error %d opening %s: %s", errno, portname, strerror (errno));
        return -1;
  }

  set_interface_attribs (fd, B115200, 0);  // set speed to 115,200 bps, 8n1 (no parity)
  set_blocking (fd, 0);                // set no blocking

  write (fd, "at\r\n", 7);           // send 7 character greeting
  usleep ((7 + 25) * 1000);             // sleep enough to transmit the 7 plus

  memset(buf,'\0',100);
  n = read (fd, buf, sizeof buf);  // read up to 100 characters if ready to read

  printf("%d %s\n",n,buf);

 
  write (fd, "ati\r\n", 7);           // send 7 character greeting
  usleep ((7 + 25) * 1000);             // sleep enough to transmit the 7 plus

  memset(buf,'\0',100);
  n = read (fd, buf, sizeof buf);  // read up to 100 characters if ready to read

  printf("%d %s\n",n,buf);


  return 0;
}
