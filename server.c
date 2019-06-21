  1 #include <stdio.h> /*pritnf, scanf */
  2 #include <stdlib.h>     /*using bzero() */
  3 #include <sys/types.h>  /* type */
  4 #include <sys/socket.h> /*socket functions */
  5 #include <netdb.h>      /* */
  6 #include <string.h>      /* using atoi() */
  7 #include <netinet/in.h>  /*struture, endian because many systems only implement that one. */
  8 
  9 int main(int argc, char* (*argv)){
 10     int serverPort = 0;
 11     int serverSocket = 0;
 12     int newSocket = 0;
 13     int returnStatus = 0;
 14     struct sockaddr_in simpleServer;
 15     struct sockaddr_in simpleClient;
 16     char buffer[256];
 17     /* Create a streaming socket */
 18     serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
 19     if(serverSocket == -1){
 20         printf("Could not create a socket !\n");
 21         exit(1);
 22     }
 23     else{
 24         printf("Socket creat!\n");
 25     }
 26       
 27     serverPort = atoi(argv[1]);
 28     memset(&simpleServer,'\0', sizeof(simpleServer));
 29     simpleServer.sin_family = AF_INET;   
 30     simpleServer.sin_addr.s_addr = htonl(INADDR_ANY);
 31     simpleServer.sin_port = htons(serverPort);
 32     returnStatus = bind(serverSocket, 
 33                     (struct sockaddr*)&simpleServer,
 34                                     sizeof(simpleServer));
 35     if(returnStatus == 0){
 36         printf("Bind to port %s! \n",argv[1]);
 37     }
 38     else{
 39         printf("Could not bind to address %d!\n",returnStatus);
 40         close(serverSocket);
 41         exit(1);
 42     }
 43 
 44     listen(serverSocket,5);
 45     printf("Listening...!\n");
 46     newSocket = accept(serverSocket,(struct sockaddr*)&simpleClient,&simpleClient);
 47     strcpy(buffer,"Nice to meet you!");
 48     send(newSocket,buffer,strlen(buffer),0);
 49     if(send != -1){
 50         printf("Sent message: %s\n",buffer);
 51     }
 52     printf("Closing the connection.\n");
 53     return 0;
 54 }
