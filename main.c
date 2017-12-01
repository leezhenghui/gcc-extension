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
	return 10;
}

int wrapper_log() {
	void* args = __builtin_apply_args();
	void (* fn)() = (void (*) ()) log;
	void* result = __builtin_apply(fn, args, sizeof(args));
	printf(" >>> %p\n", result);
	 __builtin_return(result);
}

int main(void) 
{
	const char* str_en = "Hello, World";
	const char* str_cn = "你好, 世界"; 
	int reval = wrapper_log(str_en);
	printf("reval_en: %d\n", reval);
	reval = wrapper_log(str_cn);
	printf("reval_cn: %d\n", reval);
	return 0;
}
