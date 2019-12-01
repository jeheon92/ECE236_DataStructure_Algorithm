#include "HW_4_Scheduler.h"
void manageReadyQueue(int currentTime, ProcessQueueType *readyQ, ProcessQueueType *runningQ) {
	heapSort(readyQ);

	ProcessElement* temp;
	for (int i = getQueueSize(readyQ); i > 0; i--) {
		temp = dequeueProcess(readyQ);
		if (temp->arriveTime == currentTime) {
			enqueueProcess(runningQ, temp);
			heapSort(runningQ);
		}
		else {
			enqueueProcess(readyQ, temp);
		}
	}
}

int executeRunningQueue(int *currentTime, ProcessQueueType *readyQ, ProcessQueueType *runningQ, ProcessQueueType *endedQ) {
	if (!isEmptyQueue(runningQ)) {
		ProcessElement* runningProcess = runningQ->queue[runningQ->front + 1 % MAX_ELEMENT];	// peek
		if (--(runningProcess->restTime) == 0) {
			enqueueProcess(endedQ, dequeueProcess(runningQ));

			printf("\n\n%s process will be terminated.\n", runningProcess->name);
			printf("End time of %s process : %d sec\n\n", runningProcess->name, *currentTime);
			Sleep(2000);
		}
	}

	manageReadyQueue(*currentTime, readyQ, runningQ);

	system("cls");
	printf("current time : %d sec (starting at 0 sec)\n\n", *currentTime);
	printf("[Current Situation]\n");
	printAll(readyQ, runningQ, endedQ);

	Sleep(2000);

	if (isEmptyQueue(readyQ) && isEmptyQueue(runningQ)) {
		system("cls");
		printf("\n\nAll processes have finished running.\n");
		printf("Last time of process execution : %d sec\n\n\n\n", *currentTime);
		printf("[Final Result]\n");
		printAll(readyQ, runningQ, endedQ);
		Sleep(5000);

		return 0;
	}
    
    (*currentTime)++;
    
	return 1;
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