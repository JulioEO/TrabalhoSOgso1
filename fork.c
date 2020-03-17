#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
Este programa demonstra o funcionamento da Syscall do Linux "fork()".
Essa Syscall duplica o processo e retorna um inteiro:
< 0 se ocorre um erro
== 0 se o processo é o processo filho que acabou de ser criado
> 0 se o processo é o processo pai que foi duplicado

O programa chama a função "fork()" 3 vezes, avisando ao usuário quando a duplicação ocorre.
Apenas o primeiro Processo imprimirá algumas linhas de texto.
No começo do programa e após cada duplicação todos os processos imprimem "Hello world!".
No final temos 8 processos (1*2*2*2) e, como esperado, 8 "Hello world!".

Os processos podem não executar sincronizadamente. Por isso, foi colocado entre parênteses na frente de cada
"Hello World!" um número que indica qual é aquele printf(). Caso a saída esteja fora de ordem, basta olhar o 
número no final da linha.
*/

int main()
{
	int n = 0;
	int first = 1;//Guarda qual o processo foi o primeiro, para garantir que apenas ele imprima algumas linhas

	if(first)
		printf("Antes de duplicar\n");
	printf("Hello world!(1)\n");


	if(fork() == 0)//Processo filho retorna 0, enquanto processo pai retorna algo maior que zero
		first = 0;
	else
		n++;
	if(first)
		printf("\nDuplicou! (2 processos)\n");

	printf("Hello world!(2)\n");


	if(fork() == 0)//Processo filho retorna 0, enquanto processo pai retorna algo maior que zero
		first = 0;
	else
		n++;
	if(first)
		printf("\nDuplicou! (4 processos)\n");

	printf("Hello world!(3)\n");


	if(fork() == 0)//Processo filho retorna 0, enquanto processo pai retorna algo maior que zero
		first = 0;
	else
		n++;
	if(first)
		printf("\nDuplicou! (8 processos)\n");

	printf("Hello world!(4)\n");


	return 0;
}