#include "Agent.h"

void Agent:: Move()
{
    srand(time(NULL));

    int direction = 0;

    //am o problema cu armor->weight, la accesare nu imi da valoarea ok...
    pos = 0;
    pos = (int) (visibility/2 * armor->weight + 1);

    if (pos > remainingSteps) pos = remainingSteps;

    remainingSteps -= pos;
    my_map.my_map[lin][col]='.';

    if (remainingSteps <= 0)
        direction=rand()%4 + 1;

    switch(direction)
    {
    case 1:
        lin-=pos;
        if (lin < 0) lin = 0;
        my_map.my_map[lin][col]='x';
        break;
    case 2:
        lin+=pos;
        if (lin > 24) lin = 24;
        my_map.my_map[lin][col]='x';
        break;
    case 3:
        col-=pos;
        if (col < 0) col = 0;
        my_map.my_map[lin][col]='x';
        break;
    case 4:
        col+=pos;
        if (col >24) col = 24;
        my_map.my_map[lin][col]='x';
        break;
    }

}
