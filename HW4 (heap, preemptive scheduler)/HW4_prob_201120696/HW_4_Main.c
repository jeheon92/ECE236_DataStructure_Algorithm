#include "HW_4_Main.h"

int main(void) {
	int currentTime = 0;

	ProcessQueueType *readyQ, *runningQ, *endedQ;

	readyQ = createQueue();
	runningQ = createQueue();
	endedQ = createQueue();

	initQueue(readyQ);
	initQueue(runningQ);
	initQueue(endedQ);

	enqueueProcess(readyQ, makeProcessElement("pro1", 1, 2, 3, 3));
	enqueueProcess(readyQ, makeProcessElement("pro2", 2, 3, 2, 2));
	enqueueProcess(readyQ, makeProcessElement("pro3", 3, 1, 4, 4));
	enqueueProcess(readyQ, makeProcessElement("pro4", 2, 1, 2, 2));
	enqueueProcess(readyQ, makeProcessElement("pro5", 4, 1, 3, 3));

	while () {

	}

	return 0;
}