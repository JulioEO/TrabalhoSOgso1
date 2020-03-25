/*
Este programa é um exemplo bem simples para o termo "CPU-Bound".


O programa chega a um número informado pelo usuário adicionando 1 desde o 0 até o número pedido.

É recomendado que o usuário insira um número de pelo menos 10 casas decimais, para que o programa tenha
um tempo de execução considerável. Para números muito pequenos, esse programa ainda é considerado I/O-Bound,
portanto, é necessário que o usuário insira um número consideravelmente grande para que o exemplo para
CPU-Bound funcione.
*/

#include <stdio.h>

int main()
{
	long int X = 0;
	printf("Até que número deseja somar?\n");
	scanf("%ld", &X);

	long int x = 0;
	while(x < X)
		x++;

	printf("Concluído. Resultado: %ld\n", x);
}