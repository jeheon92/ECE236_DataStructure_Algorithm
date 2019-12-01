#pragma once
#include "HW_4_Process.h"
#include <stdio.h>

typedef struct {
	ProcessElement *queue[MAX_ELEMENT+1];

	int front;
	int rear;
}ProcessQueueType;

ProcessQueueType* createQueue();
void initQueue(ProcessQueueType *q);
int isEmptyQueue(ProcessQueueType *q);
int isFullQueue(ProcessQueueType *q);
int getQueueSize(ProcessQueueType *q);
void enqueueProcess(ProcessQueueType *q, ProcessElement *item);
ProcessElement* dequeueProcess(ProcessQueueType *q);
void printQueue(ProcessQueueType *q);