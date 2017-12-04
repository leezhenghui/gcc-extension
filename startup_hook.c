/*
 * =====================================================================================
 *
 *       Filename:  instrument.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2017 05:01:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghui Lee (lizh), leezhenghui@gmail.com
 *   Organization:  ibm.com
 *
 * =====================================================================================
 */

#include<stdio.h>
#include  "./deps/simplelogger/simplog.h"

static void pre_invoke (void) __attribute__ ((constructor));

static void post_invoke (void) __attribute__ ((destructor));

static void pre_invoke (void) 
{
	simplog.writeLog( SIMPLOG_DEBUG, "[pre-invoke] main()");
	// printf("[pre-invoke] main()\n");
}

static void post_invoke (void) 
{
	simplog.writeLog( SIMPLOG_DEBUG, "[post-invoke] main()");
	// printf("[post-invoke] main()\n");
}

