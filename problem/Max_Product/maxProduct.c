long long getSum(struct TreeNode *root)
{
    if (!root)
        return 0;
    long long sum = root->val + getSum(root->left) + getSum(root->right);
    root->val = (int)sum;
    return sum;
}

void findMax(struct TreeNode *root, long long total, long long *ans)
{
    if (!root)
        return;

    long long sub = (long long)root->val;
    long long cur = (total - sub) * sub;
    if (cur > *ans)
        *ans = cur;

    findMax(root->left, total, ans);
    findMax(root->right, total, ans);
}

int maxProduct(struct TreeNode *root)
{
    long long ans = 0;
    long long total = getSum(root);

    findMax(root, total, &ans);

    return (int)(ans % 1000000007);
}