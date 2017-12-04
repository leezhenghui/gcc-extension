/*
 * =====================================================================================
 *
 *       Filename:  preload_hook.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/04/2017 10:37:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghui Lee (lizh), leezhenghui@gmail.com
 *   Organization:  ibm.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <errno.h>

// The function pointer use to keep a reference to the original writeLog function
void ( * orig_writeLog )( int loglvl, const char* str, ... );

/* *
 * Enable "-nostartfiles" option for ld to avoid multiple _init() link error
 * */
_init() {
	const char *err;
  printf("Loading original writeLog_\n");
	orig_writeLog = dlsym(RTLD_NEXT, "writeLog");
	if ((err = dlerror ()) != NULL) {
		fprintf (stderr, "dlsym (writeLog): %s\n", err);
	}
  printf("Loaded original writeLog_\n");
}

/* *
 * The deleagte method which will use be loaded ti fill the place of writeLog implemented
 * in the simplelogger shared object, it will pass through to invocation to that target
 *
 * */
void writeLog( int loglvl, const char* str, ... ) {
	pid_t pid;
	pid = getpid();
	char str_num[5];
	snprintf(str_num, sizeof(str_num), "%d", pid);
	
	char wrapped_str[1024];
	strcpy(wrapped_str, str);
	strcat(wrapped_str, " @pid-");
	strcat(wrapped_str, str_num);
  orig_writeLog(loglvl, wrapped_str);
}
