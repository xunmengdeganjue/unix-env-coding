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
 *  File Name    : charatatime.c
 *  Create Date  : 2015/10/09
 *  Author   	 : Li Qiyuan 
 *  Description  : This progrom is just to test the connection between the processes.
					多次快速重复执行本程序，则终端上输出将呈现输出内容交叉的情况，
					证明父进程和子进程间存在竞争。
 *-------------------------------------------------------------------------------
 */
 #include"../../include/apue.h"
 
 static void charatatime(char *);
 int main(void)
 {
	pid_t pid;
	
	TELL_WAIT();
	
	if((pid = fork()) < 0){
		err_sys("fork error");
	}else if(pid == 0){
		WAIT_PARENT();			/*and wait for parent*/
		charatatime("output from child\n");
	}else{
		charatatime("output from parent\n");
		TELL_CHILD(pid);		/*tell the child we're done*/
	}
	exit(0);
	 
 }
 static void charatatime(char *str)
 {
	 char *ptr;
	 int c;
	 setbuf(stdout,NULL);
	 for(ptr = str; (c=*ptr++)!= 0;)
		putc(c, stdout);
 }