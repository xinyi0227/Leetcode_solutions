#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *type;
    int t;
    char *s;
    int id;
} Event;

static int cmpEvent(const void *a, const void *b)
{
    const Event *x = (const Event *)a;
    const Event *y = (const Event *)b;
    if (x->t != y->t)
        return x->t - y->t;
    int px = (strcmp(x->type, "OFFLINE") == 0) ? 0 : 1;
    int py = (strcmp(y->type, "OFFLINE") == 0) ? 0 : 1;
    return px - py;
}

int *countMentions(int numberOfUsers, char ***events, int eventsSize, int *eventsColSize, int *returnSize)
{
    int n = numberOfUsers;
    Event *evs = (Event *)malloc(sizeof(Event) * eventsSize);

    for (int i = 0; i < eventsSize; i++)
    {
        evs[i].type = events[i][0];
        evs[i].t = atoi(events[i][1]);
        if (strcmp(evs[i].type, "OFFLINE") == 0)
        {
            evs[i].id = atoi(events[i][2]);
            evs[i].s = NULL;
        }
        else
        {
            evs[i].s = events[i][2];
            evs[i].id = -1;
        }
    }

    qsort(evs, eventsSize, sizeof(Event), cmpEvent);

    int *ans = (int *)calloc(n, sizeof(int));
    int *offlineUntil = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < eventsSize; i++)
    {
        int t = evs[i].t;

        while (i < eventsSize && evs[i].t == t && strcmp(evs[i].type, "OFFLINE") == 0)
        {
            int id = evs[i].id;
            offlineUntil[id] = t + 60;
            i++;
        }

        while (i < eventsSize && evs[i].t == t && strcmp(evs[i].type, "MESSAGE") == 0)
        {
            char *s = evs[i].s;
            int len = (int)strlen(s);
            char *buf = (char *)malloc((size_t)len + 1);
            memcpy(buf, s, (size_t)len + 1);

            char *tok = strtok(buf, " ");
            while (tok)
            {
                if (strcmp(tok, "ALL") == 0)
                {
                    for (int u = 0; u < n; u++)
                        ans[u]++;
                }
                else if (strcmp(tok, "HERE") == 0)
                {
                    for (int u = 0; u < n; u++)
                    {
                        if (offlineUntil[u] <= t)
                            ans[u]++;
                    }
                }
                else if (tok[0] == 'i' && tok[1] == 'd')
                {
                    int id = atoi(tok + 2);
                    if (0 <= id && id < n)
                        ans[id]++;
                }
                tok = strtok(NULL, " ");
            }

            free(buf);
            i++;
        }

        i--;
    }

    free(offlineUntil);
    free(evs);
    *returnSize = n;
    return ans;
}
