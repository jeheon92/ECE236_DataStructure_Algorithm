#pragma once
#define MAX_ELEMENT 2000
#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <string.h>

typedef struct {
	char *name;

	int priority;

	int arriveTime;
	int processingTime;
	int restTime;

}ProcessElement;

ProcessElement* makeProcessElement(char *name, int prior, int arr, int pro, int rest);