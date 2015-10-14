#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>		/*for exit()*/
#include<unistd.h>				/*for execl()*/
int main(void)
{
	pid_t pid;
	if((pid=fork())<0){
		printf("fork error!\n");
	}else if(pid == 0){/*child*/
		if(execl("/home/liqiyuan/coding/c_coding/unix/unix-env-coding/8/8.12/testinterp","testinterp","myarg1","MY ARG2",(char *)0)<0){
			printf("execl error!\n");
		}
	}else{ /*parent*/
		if(waitpid(pid,NULL,0)<0){
			printf("wait error");
		}
	}
	exit(0);
	
}


