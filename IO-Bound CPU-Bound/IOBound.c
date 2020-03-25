/*
Este é um programa exemplo que se encaixa na característica I/O-Bound.

Este exemplo se trata de uma simples calculadora com 4 operações (+ - * /).

O processo passará a maior parte do seu tempo de execução esperando pela entrada do usuário, sendo
assim, a sua execução esta limitada pela capacidade de Entrada/Saída, tornando-o um processo CPU-Bound.
*/

#include <stdio.h>

int soma(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a*b;
}

int div(int a, int b)
{
	return a/b;
}

int main()
{
	int a;
	int b;
	int op;
	int result = 0;

	printf("Informe o primeiro número: ");
	scanf("%d", &a);

	printf("Informe o segundo número: ");
	scanf("%d", &b);

	printf("Qual a operação desejada?\n");
	printf("1 => a+b\n");
	printf("2 => a-b\n");
	printf("3 => a*b\n");
	printf("4 => a/b\n");
	scanf("%d", &op);

	if(op == 1)
		result = soma(a, b);
	else if(op == 2)
		result = sub(a, b);
	else if(op == 3)
		result = mult(a, b);
	else if(op == 4)
		result = div(a, b);

	printf("O resultado é: %d\n", result);
}