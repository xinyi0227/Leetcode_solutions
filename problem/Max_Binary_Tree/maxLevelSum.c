#include <limits.h>
#include <stdlib.h>

int maxLevelSum(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    struct TreeNode **queue = (struct TreeNode **)malloc(10005 * sizeof(struct TreeNode *));
    int head = 0;
    int tail = 0;

    queue[tail++] = root;
    int maxLevel = 1;
    int maxSum = INT_MIN;
    int level = 1;

    while (head < tail)
    {
        int levelSum = 0;
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *node = queue[head++];
            levelSum += node->val;

            if (node->left != NULL)
            {
                queue[tail++] = node->left;
            }
            if (node->right != NULL)
            {
                queue[tail++] = node->right;
            }
        }

        if (levelSum > maxSum)
        {
            maxSum = levelSum;
            maxLevel = level;
        }

        level++;
    }

    free(queue);
    return maxLevel;
}