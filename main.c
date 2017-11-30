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

int log(const char* str) {
	printf("%s\n", str);
	return 0;
}

int wrapper_log() {
	void* args = __builtin_apply_args();
	printf(" >>> ");
	void* result = __builtin_apply(&log, args, sizeof(args));
	// __builtin_return(result);
	// return *((int*)result); 
}

int main(void) 
{
	const char* str_en = "Hello, World";
	const char* str_cn = "你好, 世界"; 
	wrapper_log(str_en);
	wrapper_log(str_cn);
	return 0;
}
