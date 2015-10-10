/*
 *------------------------------------------------------------------------------
 *
 *    Copyright (C) 2015-2016 Chengdu Skysoft Info&Tech Co., Ltd. All rights reserved.
 *    All source codes is distributed under the U-License.
 *
 *    CPU:        x86  
 *    RTOS:      
 *    Version:    0.50.00
 *    Released by Nick Li
 *                  2015/10/10.
 *
 *
 *  File Name    : exec.c
 *  Create Date  : 2015/10/10
 *  Author   	 : Nick
 *  Description  : this program show the function of the exec,first call the execle,then call the execlp.
 *-------------------------------------------------------------------------------
 */
#include<stdio.h>		/*for printf()*/
#include<unistd.h> 		/*for execle(),execlp() */
#include<stdlib.h> 		/*for exit()*/
#include<sys/wait.h> 	/*for wait()*/

char *env_init[] = {"USER=unknow","PATH=/tmp",NULL};

int main(void){
	pid_t pid;
	if((pid = fork())<0){
		printf("fork error!\n");
	}else if (pid == 0){ /*specify pathname,specify environment*/
		if(execle("/home/nickli/test/unix-env-coding/8/8.10/echoall","echoall","myarg1","MY ARG2",(char*)0,
		env_init)<0){
			printf("execle error\n");
		}
	}
	if(waitpid(pid,NULL,0)<0){
		printf("wait error\n");
	}
	if((pid = fork())<0){
		printf("fork error");
	}else if (pid == 0){ /*specify filename,inherit environment */
		if( execlp("echoall","echoall","only 1 arg",(char *)0) < 0 ){
			printf("execlp error\n");
		}	
	}
	exit(0);
}

