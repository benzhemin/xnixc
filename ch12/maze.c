#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef enum{
    DirectionDown = 0,
    DirectionLeft,
    DirectionUp,
    DirectionRight,
    DirectionUnknown
} Direction;

typedef struct {
    int row;
    int col;
    Direction direct;
} Point;

int maze[5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

unsigned row_max = sizeof(maze)/sizeof(maze[0]);
unsigned col_max = sizeof(maze[0])/sizeof(maze[0][0]);


BOOL boundary_check(Point p){
    if((p.row>=0 && p.row<row_max) &&
       (p.col>=0 && p.col<col_max)){

        if(maze[p.row][p.col] == 0){
            return TRUE;
        }
    }
    return FALSE;
}

void print_maze(SqStack *ps){
    int *maze_cp = malloc(sizeof(maze[0][0]) * (row_max*col_max));
    memcpy(maze_cp, maze, sizeof(maze[0][0]) * (row_max*col_max));

    Point *base = (Point *)ps->base;
    Point *top = (Point *)ps->top;

    while(base < top){
        int row = base->row;
        int col = base->col;

        *(maze_cp + row*col_max + col) = 9;

        base++;
    }

    for(int i=0; i<row_max; i++){
        for(int j=0; j<col_max; j++){
            printf("%d ", *(maze_cp+i*row_max+j));
        }
        printf("\n");
    }
    printf("\n");
}

BOOL point_visited(SqStack *ps, Point tp){
    Point *base = ps->base;
    Point *top = ps->top;

    while(base < top){
        if(base->row==tp.row && base->col==tp.col){
            return TRUE;
        }
        base++;
    }
    return FALSE;
}

void visit(SqStack *ps){

    Point cur = {0, 0, DirectionDown};
    push(ps, &cur);

    while(!stack_empty(ps)){
        Point top, temp;
        get_top(ps, &top);

        temp = top;
        switch(top.direct){
            case DirectionUp:
                temp.row--;
                break;
            case DirectionRight:
                temp.col++;
                break;
            case DirectionDown:
                temp.row++;
                break;
            case DirectionLeft:
                temp.col--;
                break;
            case DirectionUnknown:
                pop(ps, NULL);

                //backward
                pop(ps, &temp);
                temp.direct++;
                push(ps, &temp);
                continue;
        }

        if(boundary_check(temp) && !point_visited(ps, temp)){
            temp.direct = DirectionDown;//DirectionUp;
            push(ps, &temp);
            if(temp.row==row_max-1 && temp.col==col_max-1){
                print_maze(ps);
                break;
            }
            print_maze(ps);

        }else{
            top.direct++;
            pop(ps, NULL);
            push(ps, &top);
        }
    }
}

int main(void){
    SqStack stack;
    init_stack(&stack, sizeof(Point));

    visit(&stack);

    return 0;
}
