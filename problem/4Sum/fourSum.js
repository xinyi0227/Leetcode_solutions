/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
function fourSum(nums, target) {
    const result = [];
    const n = nums.length;
    
    if (n < 4) return result;
    
    // Sort the array
    nums.sort((a, b) => a - b);
    
    for (let i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;
        
        for (let j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;
            
            let k = j + 1;
            let l = n - 1;
            
            while (k < l) {
                const sum = nums[i] + nums[j] + nums[k] + nums[l];
                
                if (sum === target) {
                    result.push([nums[i], nums[j], nums[k], nums[l]]);
                    k++;
                    l--;
                    
                    while (k < l && nums[k] === nums[k - 1]) k++;

                    while (k < l && nums[l] === nums[l + 1]) l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    
    return result;
}
