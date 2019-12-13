#define TRUE	1
#define FALSE	0

void dijkstra_init(int nodes);
int choose(int* distance, int n, int* found);
void shortest_path(int start, int n, int **DISTANCE);

extern int *distance;
extern int *path;
extern int *found;