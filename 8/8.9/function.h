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

#include <stdio.h>
#include <signal.h> 

#define err_sys printf


static volatile sig_atomic_t sigflag;
static sigset_t newmask,oldmask,zeromask;

static void sig_usr(int signo);
void TELL_WAIT(void);
void TELL_PARENT(pid_t pid);
void WAIT_PARENT(void);
void TELL_CHILD(pid_t pid);
void WAIT_CHILD(void);
