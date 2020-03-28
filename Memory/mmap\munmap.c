#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


	/*mmap() e uma funcao que mapeia parte da memoria 
		e define quem tem acesso a ela*/
	/* munmap() e uma funcao que desmapeia uma parte da memoria*/
	/*nesse exemplo iremos mapear uma regiao da memoria escrever
	uma string nela ler essa regiao e demapeala*/
int main(){

	size_t pagesize = getpagesize();

	char *p;// vai conter  o endereço da regiao mapeada

	p = mmap(sbrk(0)//pega um lugar endereço igual ou maior ao progan break
		,pagesize*5,
    		PROT_READ|PROT_WRITE|PROT_EXEC//o espaço pode ser lido, escrito,executad
		 ,MAP_ANON|MAP_PRIVATE//
		 ,0,0);

    strcpy(p, "Empoleon Nº395\nIt swims as fast as a jet boat. The edges of its wings are sharp and can slice apart drifting ice.");//ecreve na regiao mapeada

    printf("%s\n", p);//le da regiao mapead

    munmap(p,pagesize);//desmapeia a regiao mapeada

    return 0;
	}
