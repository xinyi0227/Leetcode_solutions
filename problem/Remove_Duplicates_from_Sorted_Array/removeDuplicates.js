/**
 * Two-pointer approach - O(n) time, O(1) space
 */
var removeDuplicates = function(nums) {
    if (nums.length === 0)
        return 0;
    
    let slow = 0;
    for (let fast = 1; fast < nums.length; fast++) {
        if (nums[fast] !== nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    
    return slow + 1;
};

/**
 * Alternative implementation
 */
var removeDuplicates_alternative = function(nums) {
    if (nums.length === 0) 
        return 0;
    
    let writeIndex = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }
    
    return writeIndex;
};

/**
 * Using Set for comparison (not in-place, for reference)
 */
var removeDuplicates_set = function(nums) {
    const uniqueElements = [...new Set(nums)];
    
    for (let i = 0; i < uniqueElements.length; i++) {
        nums[i] = uniqueElements[i];
    }
    
    return uniqueElements.length;
};
