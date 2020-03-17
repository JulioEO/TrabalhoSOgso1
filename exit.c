#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
Este programa é uma modificação do programa "fork.c". O seu objetivo é demonstrar o uso da system call
"exit()". Para isso é utilizado a função "_exit()", sendo que ela é a Wrapper Function da system call em questão.
Obs: existe a função "exit()" que possui o mesmo nome da system call. Porém, ela não é uma primitiva das chamadas
de sistema.

A diferença entre esse programa e o anterior (fork.c) é que a saída "Hello world!(4)" é substituída por
"Hello world from parent", e antes dessa saída ser executada, todos os processos que possuem first==0
(filhos) executam "_exit(0)", que os finaliza. Resultado: Apenas 1 processo imprime "Hello world from parent",
e não 8 como em "fork.c".

Importante notar que, como em "fork.c", as saídas podem estar fora de ordem pois os processos não são executados
sincronizadamente.
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
		printf("\nDuplicou! (8 processos). Todos os processos filhos foram finalizados\n");

	if(!first)
		_exit(0);
	printf("Hello world from parent!\n");


	return 0;
}