int helper(struct TreeNode *node, int curr)
{
    if (!node)
        return 0;

    curr = (curr << 1) | node->val;

    if (!node->left && !node->right)
    {
        return curr;
    }

    return helper(node->left, curr) + helper(node->right, curr);
}

int sumRootToLeaf(struct TreeNode *root)
{
    return helper(root, 0);
}