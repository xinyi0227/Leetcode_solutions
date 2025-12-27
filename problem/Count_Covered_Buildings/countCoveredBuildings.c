#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SZ 100001

static int xMinArr[SZ], xMaxArr[SZ], yMinArr[SZ], yMaxArr[SZ];

static int imax(int a, int b) { return a > b ? a : b; }
static int imin(int a, int b) { return a < b ? a : b; }

int countCoveredBuildings(int n, int **buildings, int buildingsSize, int *buildingsColSize)
{
    int M = 0, N = 0;
    for (int i = 0; i < buildingsSize; i++)
    {
        int x = buildings[i][0], y = buildings[i][1];
        M = imax(M, x);
        N = imax(N, y);
    }

    memset(xMaxArr, 0, sizeof(int) * (N + 1));
    memset(yMaxArr, 0, sizeof(int) * (M + 1));

    for (int i = 0; i <= N; i++)
        xMinArr[i] = INT_MAX;
    for (int i = 0; i <= M; i++)
        yMinArr[i] = INT_MAX;

    for (int i = 0; i < buildingsSize; i++)
    {
        int x = buildings[i][0], y = buildings[i][1];
        xMinArr[y] = imin(xMinArr[y], x);
        xMaxArr[y] = imax(xMaxArr[y], x);
        yMinArr[x] = imin(yMinArr[x], y);
        yMaxArr[x] = imax(yMaxArr[x], y);
    }

    int cnt = 0;
    for (int i = 0; i < buildingsSize; i++)
    {
        int x = buildings[i][0], y = buildings[i][1];
        int coverX = (xMinArr[y] < x) & (x < xMaxArr[y]);
        int coverY = (yMinArr[x] < y) & (y < yMaxArr[x]);
        cnt += (coverX & coverY);
    }
    return cnt;
}
