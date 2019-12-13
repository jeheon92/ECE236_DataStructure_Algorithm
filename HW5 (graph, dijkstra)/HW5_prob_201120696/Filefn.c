#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>

char*** station_init(char ***STATION)
{
	FILE *f_station;
	int i=0,j=0;
	int n=0,m=0;
	f_station=fopen("station.txt","r");
	fscanf(f_station,"%d\t%d",&n,&m);
	
	STATION=(char***)malloc(sizeof(char**)*n);

	for(i=0;i<n;i++){
		STATION[i]=(char**)malloc(sizeof(char*)*m);
		for(j=0;j<m;j++){
			STATION[i][j]=(char*)malloc(20*sizeof(char));
		}
	}
	fclose(f_station);
	return STATION;
}

char*** station_input(char ***STATION)
{
	FILE *f_station;
	int i=0,j=0;
	int n=0,m=0;
	f_station=fopen("station.txt","r");
	fscanf(f_station,"%d\t%d",&n,&m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			fscanf(f_station,"%s",STATION[i][j]);
		}
	}
	fclose(f_station);
	return STATION;
}

char*** station_print(char ***STATION)
{
	FILE *f_station;
	int i=0,j=0;
	int n=0,m=0;
	f_station=fopen("station.txt","r");
	fscanf(f_station,"%d\t%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%3d.%20s",j,STATION[i][j]);
			if(j%3==2)printf("\n");
			else printf("|");
		}
	}
	fclose(f_station);
	return STATION;
}

int** dist_init(int **DISTANCE)
{
	FILE *f_dist;
	int i=0,j=0;
	int n=0,m=0;

	f_dist=fopen("dist.txt","r");
	fscanf(f_dist,"%d\t%d",&n,&m);

	DISTANCE=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		DISTANCE[i]=(int*)malloc(sizeof(int)*m);
	}
	fclose(f_dist);
	return DISTANCE;
}

int** dist_input(int **DISTANCE)
{
	FILE *f_dist;
	int i=0,j=0;
	int n=0,m=0;
	char temp[5];

	f_dist=fopen("dist.txt","r");
	fscanf(f_dist,"%d\t%d",&n,&m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			memset(temp,0,5);
			fscanf(f_dist,"%s",temp);
			DISTANCE[i][j]=atoi(temp);
		}
	}
	fclose(f_dist);
	return DISTANCE;
}

int** dist_print(int **DISTANCE)
{
	FILE *f_dist;
	int i=0,j=0;
	int n=0,m=0;

	f_dist=fopen("dist.txt","r");
	fscanf(f_dist,"%d\t%d",&n,&m);
	printf("%d\t%d\n",n,m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%5d",DISTANCE[i][j]);
		}
	}
	fclose(f_dist);
	return DISTANCE;
}

int node_count()
{
	FILE *f_station;
	int i=0,j=0;
	int n=0,m=0;
	f_station=fopen("station.txt","r");
	fscanf(f_station,"%d\t%d",&n,&m);

	return m;
}