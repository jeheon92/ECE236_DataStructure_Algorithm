#pragma once
#include "HW_4_ProcessQueue.h"
#include "HW_4_ProcessHeap.h"
#include <Windows.h>

#define BAR "==========================================================================="
#define SLEEP_TIME 2000

void manageReadyQueue(int currentTime, ProcessQueueType *readyQ, ProcessQueueType *runningQ);
int executeRunningQueue(int *currentTime, ProcessQueueType *readyQ, ProcessQueueType *runningQ, ProcessQueueType *endedQ);
void printAll(ProcessQueueType *readyQ, ProcessQueueType *runningQ, ProcessQueueType *endedQ);