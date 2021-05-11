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
	
	//Creation du socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("impossible de creer le socket");
	}
	puts("Socket cree");
	
	//Preparation de la structuresockaddr_in
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	
	//Mapping
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//Affichage du message d'erreur
		perror("Echec du mapping. Erreur");
		return 1;
	}
	puts("Mapping termine");
	
	//Ecoute du Socket
	listen(socket_desc , 3);
	
	//Acception de connection entrante
	puts("En attente des connections client...");
	c = sizeof(struct sockaddr_in);
	
	//acceptation de la connection en provenance du client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("acceptation du protocole refuse");
		return 1;
	}
	puts("Connection accepted");
	
	//Reception du message depuis le client
	while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
	{
		//renvoie du message vers le client
		if (client_message[0] == 49)
		{
		 	if(d)
			{
		        //affiche la liste de document sur le serveur
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
		puts("Client deconnecte");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("Echec de reception");
	}
	
	return 0;
}