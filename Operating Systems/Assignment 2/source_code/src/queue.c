#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t* q) {
	return (q->size == 0);
}

void enqueue(struct queue_t* q, struct pcb_t* proc) {
	/* TODO: put a new process to queue [q] */
	q->proc[q->size] = proc;
	q->size++;
	return;
}

struct pcb_t* dequeue(struct queue_t* q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t* pr = NULL;
	int i, j;
	for (i = 0; i < q->size; i++) {
		if (pr == NULL || pr->priority < q->proc[i]->priority) {
			pr = q->proc[i];
			j = i;
		}
	}
	if (pr != NULL) {
		q->proc[j] = q->proc[q->size - 1];
		q->size--;
	}
	return pr;
}

