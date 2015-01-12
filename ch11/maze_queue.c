#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "queue.h"

typedef enum{
	DirectUp = 0,
	DirectRight,
	DirectDown,
	DirectLeft,
	DirectUnknown
}Direct;

typedef struct{
	int row;
	int col;
	Direct direct;
}Point;

int maze[5][5] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

int row_max = sizeof(maze)/sizeof(maze[0]);
int col_max = sizeof(maze[0])/sizeof(maze[0][0]);

BOOL border_check(Point p){
	if((p.row<row_max && p.row>=0) &&
	   (p.col<col_max && p.col>=0)){

		if(maze[p.row][p.col] == 0){
			return TRUE;
		}
	}
	return FALSE;
}

void print_maze(){
	for(int i=0; i<row_max; i++){
		for(int j=0; j<col_max; j++){
			printf("%d, ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	sleep(1);
}

#define VISITED_MARK 	9
void mark_visited(Point p){
	maze[p.row][p.col] = VISITED_MARK;
}

void visit_maze(SqQueue *Q){
	Point start = {0, 0, DirectUp};
	mark_visited(start);

	enqueue(Q, &start);

	while(!queue_empty(Q)){
		Point rear, temp;
		dequeue(Q, &rear);

		if(rear.row==(row_max-1) && rear.col==(col_max-1)){
			printf("reach end!\n");
			break;
		}

		for(Direct di=rear.direct; di<DirectUnknown; di++){
			temp = rear;
			temp.direct = DirectUp;
			BOOL flag = TRUE;
			
			switch(di){
				case DirectUp:
					temp.row--;
					break;
				case DirectRight:
					temp.col++;
					break;
				case DirectDown:
					temp.row++;
					break;
				case DirectLeft:
					temp.col--;
					break;
				case DirectUnknown:
					flag = FALSE;
			}

			if(flag && border_check(temp)){
				mark_visited(temp);

				enqueue(Q, &temp);
				print_maze();
			}
		}
	}
}

int main(void){
	SqQueue Q;
	init_sequeue(&Q, sizeof(Point));

	visit_maze(&Q);

	return 0;
}