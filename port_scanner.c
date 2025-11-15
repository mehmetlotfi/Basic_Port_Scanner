#include "stdio.h"
#include "string.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "sys/socket.h"

int check_port (const char *ip , int port)
{
	int sock;
	struct sockaddr_in server_addr;
	sock = socket (AF_INET , SOCK_STREAM , 0);
	if (sock < 0)
	{
	    fprintf (stderr , "[-] ERROR in Socket Creation.\n");
	    return -1;
	}
	memset (&server_addr , 0 , sizeof (server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (port);
	if (inet_pton (AF_INET , ip , &server_addr.sin_addr) <= 0)
	{
		fprintf (stderr , "[-] Invalid address.\n");
		close (sock);
		return -1;
	}
	int result = connect (sock , (struct sockaddr *) &server_addr , sizeof (server_addr));
	close(sock);
	return !result;
	//return result == 0 ? 1 : 0;
}

int main (int argc , char ** argv)
{
	
	if (argc != 2)
	{

		fprintf (stderr , "[-] usage : %s <ip>\n" , argv [0]);
		return -1;
	}
	char * ip = argv [1];
	int start_port = 1 , end_port = 65535;
	printf ("Scanning open ports on %s...\n" , ip);
	for (int port = start_port ; port <= end_port ; port++)
		if (check_port (ip , port))
			printf ("%s:%d is open\n" , ip , port);
	printf("Port scanning completed.\nThanks\nMehmet lotfi\n");
	return 0;
}
