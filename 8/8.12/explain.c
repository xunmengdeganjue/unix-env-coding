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
		if(execl("/usr/local/sbin/echoall","echoall","myarg1","MY ARG2",(char *)0)<0){
			printf("execl error!\n");
		}
	}else{ /*parent*/
		if(waitpid(pid,NULL,0)<0){
			printf("wait error");
		}
	}
	exit(0);
	
}


