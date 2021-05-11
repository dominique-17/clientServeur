
#include <stdio.h>	//printf
#include <string.h>	//strlen
#include <sys/socket.h>	//socket
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>

int main(int argc , char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[2000] , server_reply[2000];
	
	//Creation du socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Impossible de creer le socket");
	}
	puts("Socket cree");
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connection au serveur distant
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("Echec de la connection au Serveur. Erreur");
		return 1;
	}
	
	puts("Connecte\n");
	
	//gardons la communication ouverte avec le serveur
	while(1)
	{
		
		printf("%s\n", "Que voulez-vous faire?");
		printf("%s\n", "1- Lister les fichiers du repertoire");
		printf("%s\n", "2- Lister un fichier particulier");
		printf("%s\n", "3- Supprimer les fichiers du repertoire");
		scanf("%s" , message);
		
		//envoie des choix vers le serveur
		if( send(sock , message , strlen(message) , 0) < 0)
		{
			puts("Echec de transmission de la demande");
			return 1;
		}
		
		//reception du traitement des donnees du serveur
		if( recv(sock , server_reply , 2000 , 0) < 0)
		{
			puts("Echec de reception");
			break;
		}
		
		puts("Reponse Du Serveur :");
		puts(server_reply);
	}
	
	close(sock);
	return 0;
}