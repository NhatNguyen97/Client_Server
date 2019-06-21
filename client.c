  1 #include <stdio.h>
  2 #include <sys/types.h>
  3 #include <sys/socket.h>
  4 #include <netdb.h>
  5 #include <string.h>
  6 #include <netinet/in.h>
  7 #include <stdlib.h>
  8 int main(int argc, char *argv[]){
  9     int clientSocket = 0;
 10     int clientPort = 0;
 11     int returnStatus = 0;
 12     char buffer[256] ={0};
 13     struct sockaddr_in simpleServer = {0};
 14     /* creat a streaming socket in client*/
 15     clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
 16     if (clientSocket == -1){
 17         printf("Could not create a socket!\n");
 18         exit(1);
 19     }
 20     else{
 21         printf("Socket client created!\n");
 22     }
 23     clientPort = atoi(argv[1]);
 24     /*set up the address argument for the sever address */
 25     memset(&simpleServer,'\0', sizeof(simpleServer));
 26     simpleServer.sin_family = AF_INET;
 27     simpleServer.sin_addr.s_addr = inet_addr("127.0.0.1");
 28     simpleServer.sin_port = htons(clientPort);
 29 
 30     /*connect to the address and port with our socket */
 31     returnStatus = connect(clientSocket,
 32                                 (struct sockaddr*)&simpleServer,
 33                                             sizeof(simpleServer));
 34     if (returnStatus == 0){
 35         printf("Connect to server sucsessful !\n");
 36     }
 37     else{
 38         printf("Could not connect to address!\n");
 39         close(clientSocket);
 40         exit(1);
 41     }
 42     /* receive the message from the server */
 43     recv(clientSocket,buffer,sizeof(buffer),0);
 44     if(recv != -1){
 45         printf("Data Received: %s\n",buffer);
 46     }
 47     printf("Closing the connection.\n");
 48     return 0;
 49 }
