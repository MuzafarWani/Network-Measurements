#include <arpa/inet.h> 
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include<time.h>

int size=32768;
int ntimes=100;
//timer add karna hai to send and recive
int main(int argc, char* argv[]) 
{ 
    int socket_desc, client_sock, c, n,t=0,nt;
    long int bt=0; 
    struct sockaddr_in server, client; 
    double message[size],tt,tot=0; 
    int i; 
    clock_t ti;
  
    // Create socket 
    socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
    if (socket_desc == -1) { 
        printf("Could not create socket"); 
    } 
    puts("Socket created"); 
  
    // Prepare the sockaddr_in structure 
    server.sin_family = AF_INET; 
    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_port = htons(8080); 
  
    // Bind the socket 
    if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) { 
  
        // print the error message 
        perror("bind failed. Error"); 
        return 1; 
    } 
    puts("bind done"); 
  
    // lsiten to the socket 
    listen(socket_desc, 3); 
    
    puts("Waiting for incoming connections..."); 
    c = sizeof(struct sockaddr_in); 
  
    // accept connection from an incoming client 
    client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c); 
  
    if (client_sock < 0) { 
        perror("accept failed"); 
        return 1; 
    } 
  
    puts("Connection accepted"); 
    
   
    nt=ntimes;
    while (nt>0) {
    
    ti=clock();
    n = recv(client_sock, &message, size, 0); bt=bt+n;
    ti=clock()-ti;
     tt=((double)ti)/CLOCKS_PER_SEC;
     tot=tot+tt;
  //  printf("Number of bytes read is %d ",n);
   //  for(i=0; i<(n/8);i++)
   //   printf("%lf ", message[i]); 
   //   printf("\n");
  

    
     if (n == 0) { 
        puts("Client disconnected"); 
        break;
    } 
    else if (n == -1) { 
        perror("recv failed"); 
    } 
     nt--;    
 } 
 printf("Total time took %f seconds to execute \n", tot);
 printf("Total number of bytes received %ld \n", bt);
  return 0; 
 }   
