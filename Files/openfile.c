

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/*
Este programa demonstra o funcionamento da Syscall do Linux "open()".
Essa Syscall abre um arquivo ou o cria caso não haja um.
< 0 se ocorre um erro
== 0 se o processo é o processo filho que acabou de ser criado


O programa chama a função "open()" que abre um arquivo e escreve "Hello World" e em seguida o fecha.
*/

int main(int argc, char const *argv[])
{
	int fd;

	fd=open("TextFile",O_CREAT);
	write(fd,stdin,14);
	close(fd);
	return 0;
}