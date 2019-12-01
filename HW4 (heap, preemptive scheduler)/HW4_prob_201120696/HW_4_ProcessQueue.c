#include "HW_4_ProcessQueue.h"

ProcessQueueType* createQueue() {
	ProcessQueueType *queue;
	queue = (ProcessQueueType*)malloc(sizeof(ProcessQueueType));
	return queue;
}
void initQueue(ProcessQueueType *q) {
	q->front = q->rear = 0;
}

int isEmptyQueue(ProcessQueueType *q) {
	return q->front == q->rear;
}

int isFullQueue(ProcessQueueType *q) {
	return q->front % MAX_ELEMENT == (q->rear + 1) % MAX_ELEMENT;
}

int getQueueSize(ProcessQueueType *q) {
	int size;

	size = q->rear - q->front;
	if (size < 0)
		size += MAX_ELEMENT;

	return size;
}

void enqueueProcess(ProcessQueueType *q, ProcessElement *item) {
	if (isFullQueue(q))
		return;

	q->rear = (q->rear + 1) % MAX_ELEMENT;

	q->queue[q->rear] = item;
}

ProcessElement* dequeueProcess(ProcessQueueType *q) {
	if (isEmptyQueue(q))
		return NULL;
	q->front = (q->front + 1) % MAX_ELEMENT;
	return q->queue[q->front];
}

void printQueue(ProcessQueueType *q) {
	int itr;

	if (isEmptyQueue(q))
	{
		printf("Queue is Empty\n");
		return;
	}

	printf("%10s %10s %15s %15s %15s\n", "Name", "Priority", "Arrive Time", "Processing Time", "Rest Time");
	if (q->front > q->rear) {
		for (itr = q->front + 1; itr < MAX_ELEMENT; itr++)
			printf("%10s %10d %15d %15d %15d\n", q->queue[itr]->name, q->queue[itr]->priority, q->queue[itr]->arriveTime, q->queue[itr]->processingTime, q->queue[itr]->restTime);
		for (itr = 0; itr <= q->rear; itr++)
			printf("%10s %10d %15d %15d %15d\n", q->queue[itr]->name, q->queue[itr]->priority, q->queue[itr]->arriveTime, q->queue[itr]->processingTime, q->queue[itr]->restTime);
	}
	else{
		for (itr = q->front + 1; itr <= q->rear; itr++)
			printf("%10s %10d %15d %15d %15d\n", q->queue[itr]->name, q->queue[itr]->priority, q->queue[itr]->arriveTime, q->queue[itr]->processingTime, q->queue[itr]->restTime);
	}
}