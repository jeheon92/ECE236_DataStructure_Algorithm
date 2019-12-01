#include "HW_4_ProcessHeap.h"

ProcessHeapType* createHeap() {
	ProcessHeapType *heap;
	heap = (ProcessHeapType*)malloc(sizeof(ProcessHeapType));
	return heap;
}

void initHeap(ProcessHeapType *h) {
	h->size = 0;
}

int isEmptyHeap(ProcessHeapType *h) {
	return h->size == 0;
}

int isFullHeap(ProcessHeapType *h) {
	return h->size == MAX_ELEMENT;
}

void insertMinHeap(ProcessHeapType *h, ProcessElement* item) {
	
}

ProcessElement* deleteMinHeap(ProcessHeapType *h) {
	
}

void heapSort(ProcessQueueType *q) {
	
}