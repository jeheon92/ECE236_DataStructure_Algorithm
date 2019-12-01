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
	if (isFullHeap(h)) return;

	int idx;
	ProcessElement *temp;
	
	idx = ++h->size;
	h->heap[idx] = item;

	while (idx != 1 && h->heap[idx]->priority < h->heap[idx / 2]->priority) {
		temp = h->heap[idx / 2];
		h->heap[idx / 2] = h->heap[idx];
		h->heap[idx] = temp;

		idx /= 2;
	}
}

ProcessElement* deleteMinHeap(ProcessHeapType *h) {
	if (isEmptyHeap(h)) return NULL;

	ProcessElement *item, *temp;
	int child;

	item = h->heap[1];

	h->heap[1] = h->heap[h->size--];
	child = 2;

	while (child <= h->size) {
		if (child < h->size && h->heap[child]->priority > h->heap[child + 1]->priority) child++;
		if (h->heap[child / 2]->priority < h->heap[child]->priority) break;
		
		temp = h->heap[child / 2];
		h->heap[child / 2] = h->heap[child];
		h->heap[child] = temp;

		child *= 2;
	}

	return item;
}

void heapSort(ProcessQueueType *q) {
	ProcessHeapType *h = createHeap();
	initHeap(h);

	while (!isEmptyQueue(q)) insertMinHeap(h, dequeueProcess(q));
	while (!isEmptyHeap(h)) enqueueProcess(q, deleteMinHeap(h));
	
	free(h);
}