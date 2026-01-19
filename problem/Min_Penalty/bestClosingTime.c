int bestClosingTime(char *customers)
{
    int max_score = 0, score = 0, best_hour = -1;
    for (int i = 0; customers[i] != '\0'; ++i)
    {
        score += (customers[i] == 'Y') ? 1 : -1;
        if (score > max_score)
        {
            max_score = score;
            best_hour = i;
        }
    }
    return best_hour + 1;
}