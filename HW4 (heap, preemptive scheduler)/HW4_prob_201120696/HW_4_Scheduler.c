#include "HW_4_Scheduler.h"
void manageReadyQueue(int currentTime, ProcessQueueType *readyQ, ProcessQueueType *runningQ) {

}

int executeRunningQueue(int *currentTime, ProcessQueueType *readyQ, ProcessQueueType *runningQ, ProcessQueueType *endedQ) {

}

void printAll(ProcessQueueType *readyQ, ProcessQueueType *runningQ, ProcessQueueType *endedQ) {
	printf("%s\n", BAR);
	printf("Ready Queue Information\n");
	printQueue(readyQ);
	printf("%s\n", BAR);
	printf("Running Queue Information\n");
	printQueue(runningQ);
	printf("%s\n", BAR);
	printf("Ended Queue Information\n");
	printQueue(endedQ);
	printf("%s\n", BAR);
}