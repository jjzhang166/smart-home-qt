#include "head.h"

#define N 64

MSG msg;

void do_set_MSG()
{
	msg.head[0] = 's';
	msg.head[1] = 't';
	msg.head[2] = ':';
	msg.type = 'e';
	msg.snum = 1;
	msg.temp[0] = (uint8_t )random(30);
	msg.temp[1] = 0;
	msg.hum[0] = (uint8_t )random(50);
	msg.hum[1] = 0;
	msg.ill = (uint32_t)random(20);
	msg.x = (uint8_t )random(10);
	msg.y = (uint8_t )random(30);
	msg.z = (uint8_t )random(50);
	msg.bet = (uint32_t)random(3);
	msg.adc = (uint32_t)random(10);
}


int main(int argc, char *argv[])
{
    // 0定义变量
    int sockfd;
    char buf[N];
    int addrlen = sizeof(struct sockaddr);
    struct sockaddr_in serveraddr;

    if(argc != 3){
        printf("usage: %s <ip> <port>\n", argv[0]);
        return -1;
    }

	srand((unsigned)time(NULL));
	
    // 1创建一个套接字--socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket err");
        exit(-1);
    }

    // 2指定服务器地址--sockaddr_in
    bzero(&serveraddr, addrlen);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    // 3连接服务器--connect
    if(connect(sockfd, (struct sockaddr *)&serveraddr, addrlen) < 0){
        perror("connect err");
        exit(-1);
    }

    // 4收发数据--recv/send
    while(1){
		do_set_MSG();
		sleep(1);
		send(sockfd, &msg, sizeof(MSG), 0);
	}

    // 5关闭连接--close
    close(sockfd);
}

