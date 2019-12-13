#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"
#include "Etc.h"
#include "Filefn.h"

char ***STATION;
int **DISTANCE;
int *distance;
int *path;
int *found;

void main()
{
	STATION = station_init(STATION);
	station_input(STATION);
	station_print(STATION);

	int start, end;
	int node_cnt = node_count();

	printf("\n��߿��� �Է����ּ���(ex: ������) : ");
	start = input_string(node_cnt, STATION);

	printf("�������� �Է����ּ���(ex: ���) : ");
	end = input_string(node_cnt, STATION);

	DISTANCE = dist_init(DISTANCE);
	dist_input(DISTANCE);

	dijkstra_init(node_cnt);
	shortest_path(start, node_cnt, DISTANCE);

	print_path(start, end, path, STATION, DISTANCE);
	print_distance(node_cnt, end, distance);
}
