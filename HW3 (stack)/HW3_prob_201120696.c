#include <stdio.h>
#include <Windows.h>

#define SLEEP_TIME 500

#define MAX_STACK_SIZE 20
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define MAZE_ROAD		' '
#define MAZE_WALL		'#'
#define MAZE_VISITED	'.'
#define MAZE_BACK_MOVED	'X'
#define MAZE_MOUSE		'M'
#define MAZE_START		'E'
#define MAZE_END		'T'

typedef struct position {
	int x;
	int y;
}position;

typedef struct {
	position *stack[MAX_STACK_SIZE];
	int top;
}StackType;

char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
	{ '#','#','#','#','#','#','#','#','#','#' },
{ 'E',' ',' ',' ',' ','#',' ',' ','#','#' },
{ '#','#','#',' ','#','#',' ','#','#','#' },
{ '#','#','#',' ',' ',' ',' ','#',' ','#' },
{ '#',' ','#','#',' ','#',' ',' ',' ','#' },
{ '#',' ','#','#',' ','#',' ','#','#','#' },
{ '#',' ',' ',' ',' ','#','#','#',' ','T' },
{ '#','#','#','#',' ',' ',' ','#',' ','#' },
{ '#',' ',' ',' ',' ','#',' ',' ',' ','#' },
{ '#','#','#','#','#','#','#','#','#','#' }
};

void init(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, position *item);
position* pop(StackType *s);
position* peek(StackType *s);

position* makePosition(int x, int y);

void printMaze();
void printStack(StackType *s);
position* positionSearch(position pos);
void positionMove(StackType *s, position *pos, position *nextPos);
void positionBackMove(StackType *s, position *pos);
int isInMaze(int x, int y);

int main(void)
{
	int itrX, itrY;
	position pos, endPos;
	StackType stack;
	position *tempPos;

	init(&stack);

	printMaze();
	printStack(&stack);

	for (itrY = 0; itrY < MAZE_HEIGHT; itrY++) {
		for (itrX = 0; itrX < MAZE_WIDTH; itrX++) {
			if (maze[itrY][itrX] == MAZE_START) {
				pos.x = itrX;
				pos.y = itrY;
				maze[itrY][itrX] = MAZE_MOUSE;
			}
			if (maze[itrY][itrX] == MAZE_END) {
				endPos.x = itrX;
				endPos.y = itrY;
			}
		}
	}
	
	while (pos.x != endPos.x || pos.y != endPos.y) {
		Sleep(SLEEP_TIME);
		printMaze();
		printStack(&stack);

		tempPos = positionSearch(pos);
		if (tempPos)
			positionMove(&stack, &pos, tempPos);
		else
			positionBackMove(&stack, &pos);
	}
	Sleep(SLEEP_TIME);
	printMaze();
	printStack(&stack);
	Sleep(SLEEP_TIME);

	return 0;
}



void init(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, position *item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

position* pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

position* peek(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];
}

position* makePosition(int x, int y) {
	position* pos;
	pos = (position*)malloc(sizeof(position));
	if (!pos)
	{
		fprintf(stderr, "position 할당 에러\n");
		exit(1);
	}

	pos->x = x;
	pos->y = y;

	return pos;
}

void printMaze() {
	int itrY, itrX;

	system("cls");
	for (itrY = 0; itrY < MAZE_HEIGHT; itrY++) {
		for (itrX = 0; itrX < MAZE_WIDTH; itrX++) {
			printf(" %c ", maze[itrY][itrX]);
		}
		printf("\n");
	}
}

void printStack(StackType *s) {
	int itr;
	printf("%4s|(%3s,%3s)|\n", "", " X ", " Y ");
	for (itr = MAX_STACK_SIZE - 1; itr > s->top; itr--)
		printf("%4d|(%3s,%3s)|\n", itr, "", "");
	for (; itr >= 0; itr--)
		printf("%4d|(%3d,%3d)|\n", itr, s->stack[itr]->x, s->stack[itr]->y);
}

position* positionSearch(position pos) {
	int x, y;

	x = pos.x - 1;
	y = pos.y;
	if (isInMaze(x, y)) {
		if (maze[y][x] == MAZE_ROAD || maze[y][x] == MAZE_END) {
			return makePosition(x, y);
		}
	}

	x = pos.x;
	y = pos.y + 1;
	if (isInMaze(x, y)) {
		if (maze[y][x] == MAZE_ROAD || maze[y][x] == MAZE_END) {
			return makePosition(x, y);
		}
	}

	x = pos.x + 1;
	y = pos.y;
	if (isInMaze(x, y)) {
		if (maze[y][x] == MAZE_ROAD || maze[y][x] == MAZE_END) {
			return makePosition(x, y);
		}
	}

	x = pos.x;
	y = pos.y - 1;
	if (isInMaze(x, y)) {
		if (maze[y][x] == MAZE_ROAD || maze[y][x] == MAZE_END) {
			return makePosition(x, y);
		}
	}

	return NULL;
}

void positionMove(StackType *s, position *pos, position *nextPos) {
	push(s, makePosition(pos->x, pos->y));
	maze[pos->y][pos->x] = MAZE_VISITED;

	pos->x = nextPos->x;
	pos->y = nextPos->y;
	maze[pos->y][pos->x] = MAZE_MOUSE;

	free(nextPos);
}

void positionBackMove(StackType *s, position *pos) {
	maze[pos->y][pos->x] = MAZE_BACK_MOVED;

	position* backPos = pop(s);
	pos->x = backPos->x;
	pos->y = backPos->y;
	maze[pos->y][pos->x] = MAZE_MOUSE;

	free(backPos);
}

int isInMaze(int x, int y) {
	if (x < 0 || x > MAZE_WIDTH)
		return 0;
	if (y < 0 || y > MAZE_HEIGHT)
		return 0;
	return 1;
}
