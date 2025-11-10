struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head)
{
    int *mpp = (int *)calloc(100001, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        mpp[nums[i]] = 1;
    }

    while (head && mpp[head->val])
    {
        head = head->next;
    }

    struct ListNode *curr = head;
    while (curr && curr->next)
    {
        while (curr->next && mpp[curr->next->val])
        {
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }

    free(mpp);
    return head;
}