#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define ARRAY_SIZE 100000000		//배열의 크기
#define MAX_DIFF 10					//배열의 값 사이의 최대 차이

int sequentialSearch(int* arr, int num);
int binarySearch(int* arr, int num, int startIdx, int endIdx);

int main(void) {
	int itr;
	int arr[ARRAY_SIZE];
	int findNum;
	int idx;
	LARGE_INTEGER frequency, startTime, endTime;
	QueryPerformanceFrequency(&frequency);

	srand(time(NULL));
	arr[0] = (rand() % MAX_DIFF) + 1;

	for (itr = 1; itr < ARRAY_SIZE; itr++)
		arr[itr] = arr[itr - 1] + (rand() % MAX_DIFF) + 1;		//현재 값 = 이전 값 + (1 ~ MAX_DIFF) 사이의 값

	findNum = arr[rand() % ARRAY_SIZE];							//찾고자 하는 값(임의로 설정)

	printf("배열 길이                   : %d\n", ARRAY_SIZE);
	printf("찾는 수                     : %d\n", findNum);

	QueryPerformanceCounter(&startTime);
	idx = sequentialSearch(arr, findNum);						//순차 탐색
	QueryPerformanceCounter(&endTime);
	printf("idx                         : %d\n", idx);
	printf("Sequential Search 소요 시간 : %.6f\n", (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart);

	QueryPerformanceCounter(&startTime);
	idx = binarySearch(arr, findNum, 0, ARRAY_SIZE - 1);			//이진 탐색
	QueryPerformanceCounter(&endTime);
	printf("idx                         : %d\n", idx);
	printf("Binary Search     소요 시간 : %.6f\n", (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart);

	return 0;
}

int sequentialSearch(int* arr, int num) {
	int idx;

	for (idx = 0; idx < ARRAY_SIZE; idx++) {
		if (arr[idx] == num)
			return idx;
	}

	return -1;
}

int binarySearch(int* arr, int num, int startIdx, int endIdx) {
	if (startIdx > endIdx) return -1;

	int idx = (startIdx + endIdx) / 2;
	int idxValue = arr[idx];

	if (idxValue == num) {
		return idx;
	}
	else if (idxValue > num) {
		endIdx = idx - 1;
	}
	else {
		startIdx = idx + 1;
	}

	return binarySearch(arr, num, startIdx, endIdx);
}