/*
 *------------------------------------------------------------------------------
 *
 *    Copyright (C) 2015-2016 Chengdu Skysoft Info&Tech Co., Ltd. All rights reserved.
 *    All source codes is distributed under the U-License.
 *
 *    CPU:        x86  
 *    RTOS:      
 *    Version:    0.50.00
 *    Released by Chengdu Skysoft Info&Tech Co., Ltd.
 *                  2015/10/09.
 *
 *
 *  File Name    : process_connection.c
 *  Create Date  : 2015/09/20
 *  Author   	 : Li Qiyuan 
 *  Description  : This progrom is just to test the connection between the processes.
 *-------------------------------------------------------------------------------
 */
 
#include"../../include/apue.h"


int main(){

	pid_t pid;
	
	TELL_WAIT();
	
	if((pid = fork())<0){
		err_sys("fork error");
	}else if (pid == 0){		/*child*/
		/*child does whatever is necessary...*/
		TELL_PARENT(getppid());	/*tell parent we're done*/
		WAIT_PARENT();			/*and wait for parent*/
		
		/*then the child continues on its way...*/
		
		exit(0);
	}else{						/*parent*/
		/*parent does whatever is necessary...*/
		TELL_CHILD(pid);		/*tell the child we're done*/
		WAIT_CHILD();			/*and wait for the child*/
		
		/*then the parent continues on its way...*/
		
		exit(0);	
	}
	return (0);
}
