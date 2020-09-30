//
// Created by 何嘉俊 on 9/30/20.
//

/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}
int setupTCPServer(int portno);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    int listen_sock, newsockfd, portno;

    listen_sock = setupTCPServer(portno);

    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    newsockfd = accept(listen_sock,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    char buffer[256];
    bzero(buffer,256);

    int n;
    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);
    n = write(newsockfd,"I got your message",18);
    if (n < 0) error("ERROR writing to socket");
    close(newsockfd);
    close(listen_sock);
    return 0;
}

int setupTCPServer(int portno)
{
    struct sockaddr_in sa_server;
    int listen_sock;

    listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_sock < 0){
        error("ERROR opening socket");
    }

    CHK_ERR(listen_sock, "socket");
    memset(&sa_server, '\0', sizeof(sa_server));

    sa_server.sin_family = AF_INET;
    sa_server.sin_addr.s_addr = INADDR_ANY;
    sa_server.sin_port = htons(portno);
    if(bind(listen_sock,
            (struct sockaddr*) & sa_server,
                    sizeof(sa_server))<0)
        error("ERROR on binding");;
    err = listen(listen_sock, 5);
    CHK_ERR(err, "listen");
    return listen_sock;
}
