#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
//#include<errno.h>
#include <signal.h>		/* for SIG_ERR */


#define MAXLINE 10
static void sig_int(int);/*信号捕捉函数*/
int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	if(signal(SIGINT,sig_int) == SIG_ERR)
	{
		printf("signal error\n");
	}
	printf("%% ");
	while(fgets(buf, MAXLINE, stdin) != NULL){
		if(buf[strlen(buf) - 1]=='\n')
		{
			buf[strlen(buf) -1] = 0;
		}
		if((pid = fork()) < 0){
			printf("fork error");
		}else if(pid == 0){
			execlp(buf, buf, (char *)0);
			exit(127);
		}
	
		/*parent*/
		if((pid =waitpid(pid,&status,0)) < 0){
			printf("waitpid error");
		}else
			printf("%%");
	}
	exit(0);
}	

void sig_int(int signo)
{
	printf("interrupt\n%%");
	sleep(3);
	printf("exit this terminal\n");
	sleep(3);
	exit(1);
}
