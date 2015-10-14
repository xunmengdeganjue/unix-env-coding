#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("hello workd form process ID %ld\n", (long)getpid());
	return 0;
}
