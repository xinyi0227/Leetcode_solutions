#include <stddef.h>

static int rows[9][10], cols[9][10], boxes[9][10];
static int sudokuSolved;

static inline int boxIndex(int r, int c)
{
    return (r / 3) * 3 + (c / 3);
}

static inline int couldPlace(int d, int r, int c)
{
    int idx = boxIndex(r, c);
    return rows[r][d] == 0 && cols[c][d] == 0 && boxes[idx][d] == 0;
}

static inline void placeNumber(int d, int r, int c, char **board)
{
    int idx = boxIndex(r, c);
    rows[r][d] += 1;
    cols[c][d] += 1;
    boxes[idx][d] += 1;
    board[r][c] = (char)('0' + d);
}

static inline void removeNumber(int d, int r, int c, char **board)
{
    int idx = boxIndex(r, c);
    rows[r][d] -= 1;
    cols[c][d] -= 1;
    boxes[idx][d] -= 1;
    board[r][c] = '.';
}

static void backtrack(int r, int c, char **board);

static void placeNextNumbers(int r, int c, char **board)
{
    if (r == 8 && c == 8)
    {
        sudokuSolved = 1;
    }
    else if (c == 8)
    {
        backtrack(r + 1, 0, board);
    }
    else
    {
        backtrack(r, c + 1, board);
    }
}

static void backtrack(int r, int c, char **board)
{
    if (board[r][c] == '.')
    {
        for (int d = 1; d <= 9; ++d)
        {
            if (couldPlace(d, r, c))
            {
                placeNumber(d, r, c, board);
                placeNextNumbers(r, c, board);
                if (!sudokuSolved)
                    removeNumber(d, r, c, board);
                else
                    return;
            }
        }
    }
    else
    {
        placeNextNumbers(r, c, board);
    }
}

void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int d = 1; d <= 9; ++d)
        {
            rows[i][d] = 0;
            cols[i][d] = 0;
            boxes[i][d] = 0;
        }
    }
    sudokuSolved = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                int d = board[i][j] - '0';
                placeNumber(d, i, j, board);
            }
        }
    }
    backtrack(0, 0, board);
}
