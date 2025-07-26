/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode *prev = &dummy;
    struct ListNode *cur = head;

    while (cur && cur->next)
    {
        struct ListNode *npn = cur->next->next;
        struct ListNode *second = cur->next;

        second->next = cur;
        cur->next = npn;
        prev->next = second;

        prev = cur;
        cur = npn;
    }

    return dummy.next;
}