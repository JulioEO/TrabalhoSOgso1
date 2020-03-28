#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
Esse programa é uma modificação do programa "fork.c". Seu objetivo é demonstrar o funcionamento do
syscall "getpid()", que possui a wrapper function com o mesmo nome "getpid()". Essa system call
retorna um inteiro que representa o id do processo em execução.

Com este programa é possível identificar qual dos processos realizou qual saída, pois a saída é da forma
"Hello world! from X" onde X é o id do processo.

Os processos não são sincronizados entre si, portanto podem ocorrer saídas fora de ordem, por isso 
existe o número entre parênteses em frente a "Hello world!".s
*/

int main()
{
	int n = 0;
	int first = 1;//Guarda qual o processo foi o primeiro, para garantir que apenas ele imprima algumas linhas

	if(first)
		printf("Antes de duplicar\n");
	printf("Hello world!(1) from: %d\n", getpid());


	if(fork() == 0)//Processo filho retorna 0, enquanto processo pai retorna algo maior que zero
		first = 0;
	else
		n++;
	if(first)
		printf("\nDuplicou! (2 processos)\n");

	printf("Hello world!(2) from: %d\n", getpid());


	if(fork() == 0)//Processo filho retorna 0, enquanto processo pai retorna algo maior que zero
		first = 0;
	else
		n++;
	if(first)
		printf("\nDuplicou! (4 processos)\n");

	printf("Hello world!(3) from: %d\n", getpid());


	if(fork() == 0)//Processo filho retorna 0, enquanto processo pai retorna algo maior que zero
		first = 0;
	else
		n++;
	if(first)
		printf("\nDuplicou! (8 processos)\n");

	printf("Hello world!(4) from: %d\n", getpid());


	return 0;
}