void inorder(struct TreeNode *node, int *vals, int *size)
{
    if (!node)
        return;
    inorder(node->left, vals, size);
    vals[(*size)++] = node->val;
    inorder(node->right, vals, size);
}

struct TreeNode *build(int *vals, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = l + (r - l) / 2;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = vals[mid];
    node->left = build(vals, l, mid - 1);
    node->right = build(vals, mid + 1, r);
    return node;
}

struct TreeNode *balanceBST(struct TreeNode *root)
{
    int *vals = (int *)malloc(10000 * sizeof(int));
    int size = 0;
    inorder(root, vals, &size);
    return build(vals, 0, size - 1);
}