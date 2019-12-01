#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>


#define MAX_LENGTH 20
#define BAR "=================================================================================================================="
#define QUANTUM 5
#define SLEEP_TIME 1000

//�ð��� ��Ÿ���� ����
int now_time = 0;
int num = 0;

//�ڷᱸ�� ����
typedef struct ProcessElement {
	char *name;

	int executionTime;
	int remainingTime;
	int arrivalTime;
}ProcessElement;


typedef struct ProcessNode {

	ProcessElement element;

	struct ProcessNode *llink;
	struct ProcessNode *rlink;

}ProcessNode;

typedef struct ProcessList {
	struct ProcessNode *front;
}ProcessList;

//�Լ� ����
int isEmptyList(ProcessList *processList);
void initList(ProcessList *processList);
void printProcessList(ProcessList *processList);
void insertProcess(ProcessList *processList, char *name, int arrivalTime, int executionTime);
void removeProcess(ProcessList *processList);
void runningTask(ProcessList *processList, int *runningTime);

int main(void)
{
	char name[MAX_LENGTH + 1];

	int execution_time;
	int runningTime = 0;

	ProcessList *processList = (ProcessList*)malloc(sizeof(ProcessList));
	initList(processList);

	system("cls");
	insertProcess(processList, "mainT", 0, 10);

	printf("%s\n", BAR);
	printf("����ð� : %d msec\n\n", now_time);
	printf("Process List Information\n\n");

	printProcessList(processList);
	printf("%s\n\n\n", BAR);

	Sleep(SLEEP_TIME);

	while (num != 1)
	{

		if (_kbhit())
		{
			if (_getch() == 's')
			{
				printf("���ο� Process�� ���� ������ �Է����ּ���(Name(���� �ִ� 20�� �ѱ� �ִ� 10��), Execution Time ������)\n");
				fflush(stdin);
				scanf("%s", name);

				fflush(stdin);
				scanf("%d", &execution_time);

				insertProcess(processList, name, now_time, execution_time);
			}

		}

		now_time++;
		runningTask(processList, &runningTime);
	}

	return 0;
}



int isEmptyList(ProcessList *processList)
{
	return (processList->front == NULL);
}


void initList(ProcessList *processList)
{
	processList->front = NULL;
}

void printProcessList(ProcessList *processList)
{
	ProcessNode *temp = processList->front;

	printf("%-21s%20s%20s%20s\n", "Name", "Arrive Time", "Execution Time", "Rest Time");

	if (temp == NULL)
		printf("		(List is empty)		\n");
	printf("%-21s%20d%20d%20d\n", temp->element.name, temp->element.arrivalTime, temp->element.executionTime, temp->element.remainingTime);
	temp = temp->rlink;
	while (temp != processList->front)
	{
		printf("%-21s%20d%20d%20d\n", temp->element.name, temp->element.arrivalTime, temp->element.executionTime, temp->element.remainingTime);
		temp = temp->rlink;
	}
}

void insertProcess(ProcessList *processList, char *name, int arrivalTime, int executionTime)
{
	ProcessNode *newProcess = (ProcessNode *)malloc(sizeof(ProcessNode));
	newProcess->element.name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newProcess->element.name, name);
	newProcess->element.arrivalTime = arrivalTime;
	newProcess->element.executionTime = executionTime;
	newProcess->element.remainingTime = executionTime;

	ProcessNode *frontNode = processList->front;

	if (isEmptyList(processList)) {
		processList->front = newProcess;
		newProcess->llink = newProcess;
		newProcess->rlink = newProcess;
	}
	else {
		ProcessNode *lastNode = frontNode->llink;
		newProcess->llink = lastNode;
		newProcess->rlink = frontNode;
		lastNode->rlink = newProcess;
		frontNode->llink = newProcess;
	}
}

void removeProcess(ProcessList *processList)
{
	ProcessNode *frontNode = processList->front;

	if (frontNode == frontNode->llink) {
		initList(processList);
	}
	else {
		ProcessNode *lastNode = frontNode->llink;
		ProcessNode *secondNode = frontNode->rlink;
		lastNode->rlink = secondNode;
		secondNode->llink = lastNode;

		processList->front = secondNode;
	}

	free(frontNode->element.name);
	frontNode->element.name = NULL;
	free(frontNode);
	frontNode = NULL;
}

void runningTask(ProcessList *processList, int *runningTime)
{
	int nowTask_ResidualTime;

	nowTask_ResidualTime = --(processList->front->element.remainingTime);

	system("cls");

	printf("%s\n", BAR);
	printf("����ð� : %d msec\n\n", now_time);
	printf("Process List Information\n\n");

	printProcessList(processList);
	printf("%s\n\n\n", BAR);

	printf("���� Task %s�� �������Դϴ�\n\n", processList->front->element.name);
	Sleep(SLEEP_TIME);
	(*runningTime)++;

	if (nowTask_ResidualTime == 0)
	{
		if (processList->front == processList->front->llink)		//���� Process�� 1���� ��
		{
			system("cls");

			printf("%s\n", BAR);
			printf("����ð� : %d msec\n\n", now_time);
			printf("Process List Information\n\n");

			printProcessList(processList);
			printf("%s\n\n\n", BAR);

			printf("���� ����Ǵ� Task %s�� ����Ǿ����ϴ�\n", processList->front->element.name);
			printf("��� Task�� ����Ǿ����ϴ�\n");

			num = 1;

			removeProcess(processList);
		}
		else
		{
			system("cls");

			printf("%s\n", BAR);
			printf("����ð� : %d msec\n\n", now_time);
			printf("Process List Information\n\n");

			printProcessList(processList);
			printf("%s\n\n\n", BAR);

			printf("���� ����Ǵ� Task %s�� ����Ǿ����ϴ�\n", processList->front->element.name);
			printf("���� Task�� �Ѿ�ϴ�\n");
			Sleep(SLEEP_TIME);

			*runningTime = 0;
			removeProcess(processList);
		}
	}
	else if (*runningTime >= QUANTUM) {									//Time Quantum�� ������ ��
		system("cls");

		printf("%s\n", BAR);
		printf("����ð� : %d msec\n\n", now_time);
		printf("Process List Information\n\n");

		printProcessList(processList);
		printf("%s\n\n\n", BAR);

		printf("%d msec�� �귯 ���� Task�� �Ѿ�ϴ�.\n", QUANTUM);
		Sleep(SLEEP_TIME);

		*runningTime = 0;
		processList->front = processList->front->rlink;
	}
}
