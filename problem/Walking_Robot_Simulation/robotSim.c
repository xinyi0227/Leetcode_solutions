#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct
{
    int x, y;
} Obstacle;

int compareObstacles(const void *a, const void *b)
{
    Obstacle *o1 = (Obstacle *)a;
    Obstacle *o2 = (Obstacle *)b;
    if (o1->x != o2->x)
        return o1->x - o2->x;
    return o1->y - o2->y;
}

int isBlocked(Obstacle *obstacles, int size, int x, int y)
{
    Obstacle target = {x, y};
    return bsearch(&target, obstacles, size, sizeof(Obstacle), compareObstacles) != NULL;
}

int robotSim(int *commands, int commandsSize, int **obstacles, int obstaclesSize, int *obstaclesColSize)
{
    Obstacle *obs = (Obstacle *)malloc(obstaclesSize * sizeof(Obstacle));
    for (int i = 0; i < obstaclesSize; i++)
    {
        obs[i].x = obstacles[i][0];
        obs[i].y = obstacles[i][1];
    }
    qsort(obs, obstaclesSize, sizeof(Obstacle), compareObstacles);

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = 0, y = 0, dir = 0, maxDist = 0;

    for (int i = 0; i < commandsSize; i++)
    {
        int cmd = commands[i];
        if (cmd == -1)
        {
            dir = (dir + 1) % 4;
        }
        else if (cmd == -2)
        {
            dir = (dir + 3) % 4;
        }
        else
        {
            for (int j = 0; j < cmd; j++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (isBlocked(obs, obstaclesSize, nx, ny))
                    break;
                x = nx;
                y = ny;
                maxDist = MAX(maxDist, x * x + y * y);
            }
        }
    }

    free(obs);
    return maxDist;
}