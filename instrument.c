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

void __cyg_profile_func_enter (void *func,  void *caller)
{
	printf("cyg_profile_func_enter\n");
	// printf("%p %p %s\n", func, caller, asctime(time(NULL)) );
}

void __cyg_profile_func_exit (void *func, void *caller)
{
	printf("cyg_profile_func_exit\n");
	// printf("x %p %p %s\n", func, caller, asctime(time(NULL)));
}
