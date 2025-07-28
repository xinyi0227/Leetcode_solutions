bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (board[r][c] == '.')
            {
                continue;
            }

            char value = board[r][c];
            int digit = value - '1';
            int boxIndex = (r / 3) * 3 + (c / 3);

            if (rows[r][digit] || cols[c][digit] || boxes[boxIndex][digit])
            {
                return false;
            }

            rows[r][digit] = true;
            cols[c][digit] = true;
            boxes[boxIndex][digit] = true;
        }
    }

    return true;
}
