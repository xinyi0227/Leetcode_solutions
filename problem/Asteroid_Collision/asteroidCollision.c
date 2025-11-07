int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize)
{
    int *stack = (int *)malloc(asteroidsSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < asteroidsSize; i++)
    {
        int asteroid = asteroids[i];
        int alive = 1;

        while (top >= 0 && asteroid < 0 && stack[top] > 0)
        {
            if (stack[top] < -asteroid)
            {
                top--;
                continue;
            }
            else if (stack[top] == -asteroid)
            {
                top--;
            }
            alive = 0;
            break;
        }

        if (alive)
        {
            stack[++top] = asteroid;
        }
    }

    *returnSize = top + 1;
    int *result = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i <= top; i++)
    {
        result[i] = stack[i];
    }

    free(stack);
    return result;
}