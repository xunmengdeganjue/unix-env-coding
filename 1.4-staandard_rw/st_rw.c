#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>

int main()
{
	int c;
	while((c = getc(stdin)) != EOF)
		if(putc(c,stdout) == EOF)
			printf("output error");

	if(ferror(stdin))
		printf("input error");
	exit(0);

}
