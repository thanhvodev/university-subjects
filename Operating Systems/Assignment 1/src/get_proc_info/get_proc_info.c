#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

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

SYSCALL_DEFINE2(get_proc_info, int, pid, struct procinfos*, info) {
  // TODO: implement the system call
	info->studentID = 1912084;

	int i;

	struct task_struct* p;
	if (pid == -1) p = current;
	else {
		if (find_get_pid(pid) == NULL) return EINVAL;
		p = get_pid_task(find_get_pid(pid),PIDTYPE_PID);
	}

	(info->proc).pid = p->pid;
	for (i = 0; i < 16; i++) (info->proc).name[i] = p->comm[i];

	(info->parent_proc).pid = p->parent->pid;
	for (i = 0; i < 16; i++) (info->parent_proc).name[i] = p->parent->comm[i];

	struct task_struct* ocp = NULL,* t;
	struct list_head* l;
	list_for_each(l, &(p->children)) {
		t = list_entry(l, struct task_struct, sibling);
		if (ocp == NULL || ocp->pid > t->pid)
			ocp = t;
		
	}
	if (ocp != NULL) {
		(info->oldest_child_proc).pid = ocp->pid;
		for (i = 0; i < 16; i++) (info->oldest_child_proc).name[i] = ocp->comm[i];
	}
	else {
		(info->oldest_child_proc).pid = -1;
	}
	return 0;
}
