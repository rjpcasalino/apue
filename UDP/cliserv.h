#include "apue.h"
#include "errors.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REQUEST 400
#define REPLY 400


#define UDP_SERV_PORT 7777
#define TCP_SERV_PORT 8888

#define SA struct sockaddr *

void err_sys(const char *, ...);
void err_quit(const char *, ...);

