#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include "Dijkstra.h"


void dijkstra_init(int nodes)
{
	distance=(int*)malloc(sizeof(int)*nodes);
	path=(int*)malloc(sizeof(int)*nodes);
	found=(int*)malloc(sizeof(int)*nodes);
}


int choose(int* distance, int n, int* found)
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)
		if( distance[i]< min && ! found[i] ){
			min = distance[i];
			minpos=i;
		}
	return minpos;
}

void shortest_path(int start, int n, int **DISTANCE) 
{  
	int i, u, w;
	for(i=0; i<n; i++)
	{
		distance[i] = DISTANCE[start][i];
		path[i] = start;
		found[i] = FALSE;
	}
	found[start] = TRUE;   
	distance[start] = 0;
	for(i=0; i<n-1; i++){
		u = choose(distance, n, found);
		found[u] = TRUE;
		for(w=0;w<n; w++) 
			if(!found[w])
				if( distance[u]+DISTANCE[u][w] < distance[w] ) {
					distance[w] = distance[u]+DISTANCE[u][w];	
					path[w] = u;
				}
	}
}

