#pragma once
#include "HW_4_Process.h"
#include "HW_4_ProcessQueue.h"

typedef struct {
	ProcessElement *heap[MAX_ELEMENT+1];
	int size;
}ProcessHeapType;

ProcessHeapType* createHeap();
void initHeap(ProcessHeapType *h);
int isEmptyHeap(ProcessHeapType *h);
int isFullHeap(ProcessHeapType *h);
void insertMinHeap(ProcessHeapType *h, ProcessElement* item);
ProcessElement* deleteMinHeap(ProcessHeapType *h);
void heapSort(ProcessQueueType *q);