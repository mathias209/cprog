#include <stdlib.h>
#include <stdio.h>

#include "include/knights_tour.h"

int move_is_possible(size_t move_id, size_t x, size_t y, size_t visited[SIZE][SIZE])
{
    if ((int)x + MOVES_X[move_id] < 0 || (int)y + MOVES_Y[move_id] < 0)
	return 0;
    return !visited[x + MOVES_X[move_id]][y + MOVES_Y[move_id]];
}

unsigned int tour_greedy(size_t start_x, size_t start_y)
{
    size_t visited[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
	for (int j = 0; j < SIZE; j++)
	    visited[i][j] = 0;
    }

    int n_moves = 0;
    while (n_moves < (SIZE * SIZE - 1)) {
	visited[start_x][start_y] = 1;

    	int min_moves = MOVE_COUNT;
	int min_moves_id = 0;
	for (int i = 0; i < MOVE_COUNT; i++) {
	    if (move_is_possible(i, start_x, start_y, visited)) {
		int n_possible = 0;
		for (int j = 0; j < MOVE_COUNT; j++) {
		    n_possible += move_is_possible(j, start_x + MOVES_X[i], start_y + MOVES_Y[i], visited);
		}
		if (n_possible == 0) {
		    return n_moves;
		} else if (n_possible < min_moves) {
		    min_moves = n_possible;
		    min_moves_id = i;
		}
	    }
	}
	start_x += MOVES_X[min_moves_id];
	start_y += MOVES_Y[min_moves_id];
	n_moves++;
    }

    return n_moves;
}

void tour_greedy_step(size_t start_x, size_t start_y)
{    
    size_t visited[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
	for (int j = 0; j < SIZE; j++)
	    visited[i][j] = 0;
    }

    int n_moves = 0;
    while (n_moves < (SIZE * SIZE - 1)) {
	visited[start_x][start_y] = 1;
	printf("\n\nMove %d!\n", n_moves);
	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j < SIZE; j++) {
		printf("[%lu]", visited[j][i]);
	    }
	    putchar('\n');
	}

    	int min_moves = MOVE_COUNT;
	int min_moves_id = 0;
	for (int i = 0; i < MOVE_COUNT; i++) {
	    if (move_is_possible(i, start_x, start_y, visited)) {
		int n_possible = 0;
		for (int j = 0; j < MOVE_COUNT; j++) {
		    n_possible += move_is_possible(j, start_x + MOVES_X[i], start_y + MOVES_Y[i], visited);
		}
		if (n_possible <= 0) {
		    printf("Dead end :(\n");
		    return;
		} else if (n_possible < min_moves) {
		    min_moves = n_possible;
		    min_moves_id = i;
		}
	    }
	}
	start_x += MOVES_X[min_moves_id];
	start_y += MOVES_Y[min_moves_id];
	n_moves++;
	getchar();
    }
}

void greedy_tour_from_each_square()
{
    int all_tours[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
	for (int j = 0; j < SIZE; j++) {
	    all_tours[i][j] = 0;
	}
    }

    for (int i = 0; i < SIZE; i++) {
	for (int j = 0; j < SIZE; j++) {
	    all_tours[i][j] = tour_greedy(i, j);
	}
    }

    for (int i = 0; i < SIZE; i++) {
	for (int j = 0; j < SIZE; j++) {
	    printf("%d\t", all_tours[j][i]);
	}
	putchar('\n');
    }
}
