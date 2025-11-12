#include <stdio.h>
#include "include/knights_tour.h"
#include <stdlib.h>

int main()
{
    greedy_tour_from_each_square();
    tour_greedy_step(1, 0);

    return 0;
}
