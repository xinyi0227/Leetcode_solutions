typedef struct
{
    int x;
    int y;
    int width;
    int height;
    int dir;
} Robot;

Robot *robotCreate(int width, int height)
{
    Robot *obj = (Robot *)malloc(sizeof(Robot));
    obj->x = 0;
    obj->y = 0;
    obj->width = width;
    obj->height = height;
    obj->dir = 0;
    return obj;
}

void robotStep(Robot *obj, int num)
{
    int perimeter = 2 * (obj->width - 1) + 2 * (obj->height - 1);
    num %= perimeter;

    if (num == 0)
    {
        if (obj->x == 0 && obj->y == 0 && obj->dir == 0)
        {
            obj->dir = 3;
        }
        else if (obj->x == obj->width - 1 && obj->y == 0)
        {
            obj->dir = 0;
        }
        else if (obj->x == obj->width - 1 && obj->y == obj->height - 1)
        {
            obj->dir = 1;
        }
        else if (obj->x == 0 && obj->y == obj->height - 1)
        {
            obj->dir = 2;
        }
        if (num == 0 && (obj->x != 0 || obj->y != 0 || obj->dir != 3))
        {
            num = perimeter;
        }
    }

    while (num > 0)
    {
        if (obj->dir == 0)
        {
            int canMove = (obj->width - 1) - obj->x;
            if (num <= canMove)
            {
                obj->x += num;
                num = 0;
            }
            else
            {
                obj->x = obj->width - 1;
                num -= canMove;
                obj->dir = 1;
            }
        }
        else if (obj->dir == 1)
        {
            int canMove = (obj->height - 1) - obj->y;
            if (num <= canMove)
            {
                obj->y += num;
                num = 0;
            }
            else
            {
                obj->y = obj->height - 1;
                num -= canMove;
                obj->dir = 2;
            }
        }
        else if (obj->dir == 2)
        {
            int canMove = obj->x;
            if (num <= canMove)
            {
                obj->x -= num;
                num = 0;
            }
            else
            {
                obj->x = 0;
                num -= canMove;
                obj->dir = 3;
            }
        }
        else if (obj->dir == 3)
        {
            int canMove = obj->y;
            if (num <= canMove)
            {
                obj->y -= num;
                num = 0;
            }
            else
            {
                obj->y = 0;
                num -= canMove;
                obj->dir = 0;
            }
        }
    }
}

int *robotGetPos(Robot *obj, int *retSize)
{
    *retSize = 2;
    int *pos = (int *)malloc(sizeof(int) * 2);
    pos[0] = obj->x;
    pos[1] = obj->y;
    return pos;
}

char *robotGetDir(Robot *obj)
{
    switch (obj->dir)
    {
    case 0:
        return "East";
    case 1:
        return "North";
    case 2:
        return "West";
    case 3:
        return "South";
    default:
        return "";
    }
}

void robotFree(Robot *obj)
{
    free(obj);
}