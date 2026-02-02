#include <math.h>
#include <float.h>

double validate(int **squares, int squaresSize, double mid)
{
    double below = 0, above = 0;
    for (int i = 0; i < squaresSize; i++)
    {
        double y0 = squares[i][1], side = squares[i][2], y1 = y0 + side;
        double b_h = fmin(y1, mid) - y0;
        double a_h = y1 - fmax(mid, y0);
        if (b_h > 0)
            below += b_h * side;
        if (a_h > 0)
            above += a_h * side;
    }
    return below >= above;
}

double separateSquares(int **squares, int squaresSize, int *squaresColSize)
{
    double l = DBL_MAX, r = -DBL_MAX;
    for (int i = 0; i < squaresSize; i++)
    {
        if (squares[i][1] < l)
            l = squares[i][1];
        if (squares[i][1] + squares[i][2] > r)
            r = squares[i][1] + squares[i][2];
    }

    for (int i = 0; i < 100; i++)
    {
        double mid = l + (r - l) / 2.0;
        if (validate(squares, squaresSize, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}