
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/*		A syscall sbrk(intptr_t i) incrementa o program break
	,que define o final do segmento de dados, i vezes e retorna
	o program break anterior. incrementar o program break tem o efeito 
	de alocar memoria para o programa*/

/*		Nesse exemplo vamos aumentar a memoria alocada ao programa em 1 bits */
 int main()
{
	void* brkprog;
	long tam;
	long tam1,tam2;

	brkprog=sbrk(0);//sbrk(0) é o mesmo que retornar o program break atual

	tam1=(long)brkprog-(long)main;//tamanho do programa em relação ao main

	printf("%li\n", tam1);

	sbrk(1);//incrementa o program break em 1

	brkprog=sbrk(0);
	tam2=(long)brkprog-(long)main;//tamanho do programa em relação ao main apos o incremenmto

	printf("%li\n", tam2);

	tam=tam2-tam1;
	printf("%li\n", tam);

	return 0;
}