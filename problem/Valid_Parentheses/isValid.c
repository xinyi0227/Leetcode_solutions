bool isValid(char *s)
{
    int len = strlen(s);
    if (len % 2 != 0)
        return false;

    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        else
        {
            if (top == -1)
            {
                free(stack);
                return false;
            }

            char opening = stack[top--];

            if ((c == ')' && opening != '(') ||
                (c == ']' && opening != '[') ||
                (c == '}' && opening != '{'))
            {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);
    free(stack);
    return result;
}

bool isValid_array(char *s)
{
    int len = strlen(s);
    if (len % 2 != 0)
        return false;

    char stack[10000];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        else
        {
            if (top == -1)
                return false;

            char opening = stack[top--];

            if ((c == ')' && opening != '(') ||
                (c == ']' && opening != '[') ||
                (c == '}' && opening != '{'))
            {
                return false;
            }
        }
    }

    return top == -1;
}
