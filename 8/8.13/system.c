#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int system(const char *cmdstring)
{
	pid_t pid;
	int status;
	if(cmdstring == NULL){
		return (1);
	}
	if((pid = fork())<0){
		status  =-1;
	}else if(pif ==0){/*child*/
		execl("/bin/sh","sh","-c",cmdstring,(char *)0);
		_exit(127); /*execl error*/
	}else{
		while(waitpid(pid,&status,0)<0){
			if(errno != EINTR){
				status = -1;/*error other than EINTR from waitpid()*/
				break;
			}
		}
	}
	return (status);
}
int main(void)
{
	int status;
	if((status =system("date"))<0){
		printf("system() error!\n");
	}
	pr_exit(status);
	
	if((status = system(nosuchcommand))<0){
		printf("system() error!\n");
	}
	pr_exit(status);
	
	if((status = system("who;exit 44"))<0){
		printf("system() error!\n");
	}
	pr_exit(status);
	
	exit(0);
}


