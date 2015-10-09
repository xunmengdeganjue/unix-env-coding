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
 *                  2015/10/09.
 *
 *
 *  File Name    : charatatime.c
 *  Create Date  : 2015/10/09
 *  Author   	 : Li Qiyuan 
 *  Description  : 本文件中的接口，采用信号机制，用以避免进程间的“竞争”出现。
 *-------------------------------------------------------------------------------
 */

#include "function.h"

static void sig_usr(int signo){
	sigflag = 1;
} 

void TELL_WAIT(void){
	if(signal(SIGUSR1,sig_usr) == SIG_ERR){
		err_sys("signal(SIGUSR1) error");
	}
	if(signal(SIGUSR2,sig_usr) == SIG_ERR){
		err_sys("signal(SIGUSR2) error");
	}
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);
	/*Block SIGUSR1 and SIGUSR2, and save current signal mask*/
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0){
		err_sys("SIG_BLOCK error");
	}
}
void TELL_PARENT(pid_t pid){
	kill(pid, SIGUSR2); /*tell parent we're done*/
}
void WAIT_PARENT(void){
	while(sigflag == 0){
		sigsuspend(&zeromask);/*wait for parent*/
	}
	sigflag = 0;
	/*Reset signal mask to original value*/
	if(sigprocmask(SIG_SETMASK, &oldmask,NULL) < 0){
		err_sys("SIG_SETMASK error!");
	}
}
void TELL_CHILD(pid_t pid){
	kill(pid,SIGUSR1); 		/*tell child we're done*/
}
void WAIT_CHILD(void)
{
	while(sigflag ==0){
		sigsuspend(&zeromask); 	/*wait for the child*/
	}
	sigflag = 0;
	/*Reset signal mask to original value*/
	if (sigprocmask(SIG_SETMASK, & oldmask, NULL) < 0){
		err_sys("SIG_SETMASK error!");
	}
	
}