/*
 * =====================================================================================
 *
 *       Filename:  hello_world.c
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

int main(void) 
{
	const char* str_en = "Hello, World";
	const char* str_cn = "你好, 世界"; 
	printf("%s\n %s\n", str_en, str_cn);
	return 0;
}
