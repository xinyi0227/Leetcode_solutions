/**
 * Binary search approach - O(log n) time, O(1) space
 */
var searchInsert = function(nums, target) {
    let left = 0, right = nums.length - 1;
    
    while (left <= right) {
        let mid = Math.floor(left + (right - left) / 2);
        
        if (nums[mid] === target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
};

/**
 * Recursive binary search implementation
 */
var searchInsert_recursive = function(nums, target) {
    function binarySearch(left, right) {
        if (left > right) {
            return left;
        }
        
        let mid = Math.floor(left + (right - left) / 2);
        
        if (nums[mid] === target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearch(mid + 1, right);
        } else {
            return binarySearch(left, mid - 1);
        }
    }
    
    return binarySearch(0, nums.length - 1);
};

/**
 * Template-style binary search
 */
var searchInsert_template = function(nums, target) {
    let left = 0, right = nums.length;
    
    while (left < right) {
        let mid = Math.floor(left + (right - left) / 2);
        
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
};

/**
 * Using built-in methods (for comparison)
 */
var searchInsert_builtin = function(nums, target) {
    let index = nums.indexOf(target);
    if (index !== -1) {
        return index;
    }

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > target) {
            return i;
        }
    }
    
    return nums.length;
};
