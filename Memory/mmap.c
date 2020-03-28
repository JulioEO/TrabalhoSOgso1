#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


	/*mmap() e uma funcao que mapeia parte da memoria 
		e define quem tem acesso a ela*/
	/* munmap() e uma funcao que desmapeia uma parte da memoria*/
int main(){

	size_t pagesize = getpagesize();

	char *p;

	p = mmap(sbrk(0),pagesize*5,
    PROT_READ|PROT_WRITE|PROT_EXEC,MAP_ANON|MAP_PRIVATE,0,0);

    strcpy(p, "Empoleon Nº395\nIt swims as fast as a jet boat. The edges of its wings are sharp and can slice apart drifting ice.");

    printf("%s\n", p);

    munmap(p,pagesize);

    return 0;
	}