/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * Iterative approach with dummy node - O(m+n) time, O(1) space
 */
var mergeTwoLists = function(list1, list2) {
    const dummy = new ListNode(0);
    let current = dummy;
    
    while (list1 && list2) {
        if (list1.val <= list2.val) {
            current.next = list1;
            list1 = list1.next;
        } else {
            current.next = list2;
            list2 = list2.next;
        }
        current = current.next;
    }
    
    current.next = list1 || list2;
    
    return dummy.next;
};

/**
 * Recursive approach - O(m+n) time, O(m+n) space
 */
var mergeTwoLists_recursive = function(list1, list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    
    if (list1.val <= list2.val) {
        list1.next = mergeTwoLists_recursive(list1.next, list2);
        return list1;
    } else {
        list2.next = mergeTwoLists_recursive(list1, list2.next);
        return list2;
    }
};

/**
 * Iterative without dummy node
 */
var mergeTwoLists_no_dummy = function(list1, list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    
    let head;
    if (list1.val <= list2.val) {
        head = list1;
        list1 = list1.next;
    } else {
        head = list2;
        list2 = list2.next;
    }
    
    let current = head;
    
    while (list1 && list2) {
        if (list1.val <= list2.val) {
            current.next = list1;
            list1 = list1.next;
        } else {
            current.next = list2;
            list2 = list2.next;
        }
        current = current.next;
    }
    
    current.next = list1 || list2;
    return head;
};
