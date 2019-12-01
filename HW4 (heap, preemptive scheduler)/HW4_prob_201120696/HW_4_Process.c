#include "HW_4_Process.h"
ProcessElement* makeProcessElement(char *name, int prior, int arr, int pro, int rest) {
	ProcessElement *tempElement;
	char* tempStr;

	tempElement = (ProcessElement*)malloc(sizeof(ProcessElement));
	tempStr = (char*)malloc(sizeof(char)*strlen(name) + 1);

	strcpy(tempStr, name);
	tempElement->name = tempStr;
	tempElement->priority = prior;
	tempElement->arriveTime = arr;
	tempElement->processingTime = pro;
	tempElement->restTime = rest;

	return tempElement;
}