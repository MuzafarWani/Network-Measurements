#include <arpa/inet.h> 
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include<time.h>
  
// Driver code 
int main(int argc, char* argv[]) 
{   // Three arguments to be passed : 
    // 1. ip address of the server(varaiable st)
    // 2. Size of array to be passed to the server(varaiable sizearr)
    // 3. Number of times the array of size n is sent to the server(varaiable ntimes) 
    int sock,i,sizearr,ntimes; 
    struct sockaddr_in server; 
    double datasize=0;
    clock_t ti;
    char* st = argv[1];
    sizearr=atoi(argv[2]);
    ntimes= atoi(argv[3]); 
    double a[size],tt,tot=0;
    
    for(i=0;i<n;i++) {
      a[i] = i; 
    }
      
      datasize=(8*n)*ntimes;
   
    // Create socket 
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock == -1) { 
        printf("Could not create socket"); 
    } 
   // puts("Socket created"); 
  
    server.sin_addr.s_addr = inet_addr(st); 
    server.sin_family = AF_INET; 
    server.sin_port = htons(8080); 
  
    // Connect to remote server 
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) { 
        perror("connect failed. Error"); 
        return 1; 
    } 
  
  //  puts("Connected\n"); 
    ti=clock();
    
    while(ntimes>0) { 
     
      if (send(sock, a, 8*sizearr, 0) < 0) { 
        puts("Send failed"); 
        return 1; 
      } 
 
     ntimes--;
   }
   
   ti=clock()-ti;
   tt=((double)ti)/CLOCKS_PER_SEC;
   // close the socket 
    close(sock); 
   printf("Total time took %f seconds to execute \n", tt); 
   printf("Total number of Mbits sent %f \n", (datasize/125000));
     
   return 0; 
  }  
