/*
 * =====================================================================================
 *
 *       Filename:  trace.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2017 05:54:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghui Lee (lizh), leezhenghui@gmail.com
 *   Organization:  ibm.com
 *
 * =====================================================================================
 */

#include<stdio.h>
#include <time.h>

#include  "./deps/simplelogger/simplog.h"

void __cyg_profile_func_enter (void *func,  void *caller)
{
	// printf("cyg_profile_func_enter\n");
	simplog.writeLog( SIMPLOG_DEBUG, "cyg_profile_func_enter");
}

void __cyg_profile_func_exit (void *func, void *caller)
{
	// printf("cyg_profile_func_exit\n");
	simplog.writeLog( SIMPLOG_DEBUG, "cyg_profile_func_exit");
}
