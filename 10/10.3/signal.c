#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void sig_usr(int); /*one handler for both signals*/
int main(void)
{
	if(signal(SIGUSR1,sig_usr) == SIG_ERR){
		printf("can't catch SIGUSR1\n");
	}
	if(signal(SIGUSR2,sig_usr) == SIG_ERR){
		printf("can't catch SIGUSR2\n");
	}
	for(;;){
		pause();//let the program 
	}
}
static void sig_usr(int signo){/*argument is signal number*/
	if (signo == SIGUSR1){
		printf("received SIGUSR1 [%d]\n",signo);
	}else if (signo == SIGUSR2){
		printf("received SIGUSR2 [%d]\n",signo);
	}else{
		printf("received signal %d \n",signo);
	}
}