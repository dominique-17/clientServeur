/*
	C socket server example
*/

#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include <dirent.h>

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , read_size, i;
	struct sockaddr_in server , client;
	char client_message[2000];

	struct dirent *dir;
	DIR  *d = opendir("/home/dominique/Documents/test");
	DIR  *f = opendir("/home/dominique/Documents/test/1.txt");
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return 1;
	}
	puts("bind done");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	
	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}
	puts("Connection accepted");
	
	//Receive a message from client
	while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
	{
		//Send the message back to client
		//affiche la liste de document sur le serveur
		if (client_message[0] == 49)
		{
		 	if(d)
			{
				while ((dir = readdir(d)) != NULL)
				{
					printf("%s\n", dir->d_name );
					write(client_sock , dir->d_name , strlen(dir->d_name));
					
				}
				closedir(d);
			}
		}

		if (client_message[0] == 50)
		{
			write(client_sock , "1.txt" , strlen("1.txt"));
		 	if(f)
			{
				while ((dir = readdir(f)) != NULL)
				{
					printf("%s\n", dir->d_name );
					write(client_sock , dir->d_name , strlen(dir->d_name));
					
				}
				closedir(f);
			}
		}
	}
	
	if(read_size == 0)
	{
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("recv failed");
	}
	
	return 0;
}