#include"../../include/apue.h"
#include<sys/wait.h>

void pr_exit(int status)
{
	if(WIFEXITED(status)){
		printf("normal termination,exit status=%d\n",WEXITSTATUS(status));
	}else if (WIFSIGNALED(status)){
		printf("abnomal termination,signal number=%d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
		WCOREDUMP(status)?"(core file generated)":"");
#else 
	"" );
#endif
	}else if(WIFSTOPPED(status)){
		printf("chiled stopped,signal number=%d\n",WSTOPSIG(status));
	}

}

main(void)
{
	pid_t pid;
	int status;
	
 	/***************************************/
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}else if(pid == 0)
	{
		exit(7);
	}
	if(wait(&status) != pid)
	{
		err_sys("wait error");
	}else{
		pr_exit(status);
	}
	
	/***************************************/
	if((pid = fork()) < 0){
		err_sys("wait error");
	}else if (pid == 0){
		abort(); //generates SIGABRT
	}
	if(wait(&status) != pid){
		err_sys("wait error");
	}else{
		pr_exit(status);
	}
	
	/***************************************/
	if((pid = fork()) < 0){
		err_sys("fork error");
	}else if (pid == 0){
		status /= 0;  //devide by 0 generates SIGFPE
	}
	if(wait(&status) != pid){
	err_sys("wait error");
	}else{
		pr_exit(status);
	}

	exit(0);

}

