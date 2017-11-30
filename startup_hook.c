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

static void pre_invoke (void) __attribute__ ((constructor));

static void post_invoke (void) __attribute__ ((destructor));

static void pre_invoke (void) 
{
  printf("Pre-Invoke\n");
}

static void post_invoke (void) 
{
  printf("Post-Invoke\n");
}

