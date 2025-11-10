/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    let mpp = new Set(nums);
    
    while (head && mpp.has(head.val)) {
        head = head.next;
    }
    
    let curr = head;
    while (curr && curr.next) {
        while (curr.next && mpp.has(curr.next.val)) {
            curr.next = curr.next.next;
        }
        curr = curr.next;
    }
    
    return head;
};