#ifndef _GET_PROC_INFO_H_
#define _GET_PROC_INFO_H_
#include <unistd.h>

struct proc_info {  //info about a single process
	int pid;  //pid of the process
	char name[16];  //file name of the program executed
};

struct procinfos {  //info about processes we need
	long studentID;  //for the assignment testing
	struct proc_info proc;  //process with pid or current process
	struct proc_info parent_proc;  //parent process
	struct proc_info oldest_child_proc;  //oldest child process
};

long get_proc_info(pid_t pid, struct procinfos* info);
#endif
	
