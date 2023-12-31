#include "cliserv.h"

int
main()
{
 struct sockaddr_in serv, cli;
 char request[REQUEST], reply[REPLY];
 int sockfd, n, clilen;
 if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
  err_sys("socket error");
 memset(&serv, sizeof(serv), 0);
 setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &serv, sizeof(serv));
 serv.sin_family = AF_INET;
 serv.sin_addr.s_addr = htonl(INADDR_ANY);
 serv.sin_port = htons(UDP_SERV_PORT);

 if (bind(sockfd, (SA) &serv, sizeof(serv)) < 0)
  err_sys("bind error");

 for(;;) {
  clilen = sizeof(cli);
  if ((n = recvfrom(sockfd, request, REQUEST, 0, (SA) &cli, &clilen)) < 0)
   err_sys("recvfrom error");
  if (sendto(sockfd, reply, REPLY, 0, (SA) &cli, sizeof(cli)) != REPLY)
   err_sys("sendto error");
 }
}
