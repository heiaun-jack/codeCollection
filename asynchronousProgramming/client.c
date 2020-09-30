//
// Created by 何嘉俊 on 9/29/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int setupTCPClient(const char* hostname, int port)
{
    struct sockaddr_in server_addr;

    // Get the IP address from hostname
    struct hostent* hp = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sockfd < 0){
        error("ERROR opening socket");
        exit(0);
    }


    // Fill in the destination information (IP, port #, and family)
    bzero((char *) &server_addr, sizeof(server_addr));

    bcopy((char *)server->c,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    //   server_addr.sin_addr.s_addr = inet_addr ("10.0.2.14");
    server_addr.sin_port = htons(port);
    server_addr.sin_family = AF_INET;

    // Connect to the destination
    if(connect(sockfd, (struct sockaddr*) & server_addr,
               sizeof(server_addr))<0
            ){
        error("ERROR connecting");
        exit(0);
    }


    return sockfd;
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    char buffer[256];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);

    sockfd = setupTCPClient(argv[1], portno);

    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    close(sockfd);
    return 0;
}