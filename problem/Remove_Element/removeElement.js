/**
 * Two-pointer approach - O(n) time, O(1) space
 */
var removeElement = function(nums, val) {
    let slow = 0;
    
    for (let fast = 0; fast < nums.length; fast++) {
        if (nums[fast] !== val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    
    return slow;
};

/**
 * Swap with end approach
 */
var removeElement_swap = function(nums, val) {
    let i = 0;
    let n = nums.length;
    
    while (i < n) {
        if (nums[i] === val) {
            nums[i] = nums[n - 1];
            n--;
        } else {
            i++;
        }
    }
    
    return n;
};

/**
 * For-of loop with index tracking
 */
var removeElement_for_of = function(nums, val) {
    let slow = 0;
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[slow++] = nums[i];
        }
    }
    
    return slow;
};

/**
 * Filter approach (creates new array, not in-place)
 */
var removeElement_filter = function(nums, val) {
    const filtered = nums.filter(num => num !== val);

    for (let i = 0; i < filtered.length; i++) {
        nums[i] = filtered[i];
    }
    
    return filtered.length;
};
