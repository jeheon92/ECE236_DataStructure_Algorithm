#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void print_path(int start, int end, int* path, char ***STATION, int **DISTANCE)
{  
	if( path[end] != start)
		print_path(start, path[end], path, STATION, DISTANCE);
	printf("<%s->%s> %d", STATION[0][path[end]], STATION[0][end], DISTANCE[path[end]][end]);
	printf("\n");
}

void print_distance(int nodes, int end, int* distance)
{
	int i;
	printf("총 거리 %d00m\n",distance[end]);
	printf("모든 역까지의 거리(단위 100m)\n");
	for(i=0;i<nodes;i++){
		printf("%3d.%4d|", i, distance[i]);
		if(i%5==4)printf("\n");
	}
	printf("\n");
}

int input_string(int nodes,char ***STATION)
{
	char string[20];
	int i=0;
	scanf("%s",string);
	for(i=0;i<nodes && strcmp(string,STATION[0][i]);i++);
	return i;
}
