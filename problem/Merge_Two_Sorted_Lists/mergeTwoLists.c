/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode dummy = {0, NULL};
    struct ListNode *current = &dummy;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = list1 ? list1 : list2;

    return dummy.next;
}

struct ListNode *mergeTwoLists_recursive(struct ListNode *list1, struct ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists_recursive(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists_recursive(list1, list2->next);
        return list2;
    }
}

struct ListNode *mergeTwoLists_no_dummy(struct ListNode *list1, struct ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    struct ListNode *head;
    if (list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }

    struct ListNode *current = head;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = list1 ? list1 : list2;
    return head;
}
