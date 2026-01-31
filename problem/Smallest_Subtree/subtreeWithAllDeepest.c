struct Result
{
    struct TreeNode *node;
    int dist;
};

struct Result dfs(struct TreeNode *root)
{
    if (!root)
        return (struct Result){NULL, 0};

    struct Result l = dfs(root->left);
    struct Result r = dfs(root->right);

    if (l.dist > r.dist)
        return (struct Result){l.node, l.dist + 1};
    if (r.dist > l.dist)
        return (struct Result){r.node, r.dist + 1};
    return (struct Result){root, l.dist + 1};
}

struct TreeNode *subtreeWithAllDeepest(struct TreeNode *root)
{
    return dfs(root).node;
}