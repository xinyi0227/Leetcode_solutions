/**
 * Binary search approach - O(log(min(m,n))) time, O(1) space
 */
var findMedianSortedArrays = function(nums1, nums2) {
    if (nums1.length > nums2.length) {
        [nums1, nums2] = [nums2, nums1];
    }
    
    const m = nums1.length, n = nums2.length;
    let left = 0, right = m;
    
    while (left <= right) {
        const partition1 = Math.floor((left + right) / 2);
        const partition2 = Math.floor((m + n + 1) / 2) - partition1;
        
        const maxLeft1 = partition1 === 0 ? -Infinity : nums1[partition1 - 1];
        const minRight1 = partition1 === m ? Infinity : nums1[partition1];
        
        const maxLeft2 = partition2 === 0 ? -Infinity : nums2[partition2 - 1];
        const minRight2 = partition2 === n ? Infinity : nums2[partition2];
        
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 === 0) {
                return (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2;
            } else {
                return Math.max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }
    
    throw new Error("Input arrays are not sorted");
};

/**
 * Merge approach - O(m+n) time, O(m+n) space
 */
var findMedianSortedArrays_merge = function(nums1, nums2) {
    const merged = [];
    let i = 0, j = 0;
    
    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] <= nums2[j]) {
            merged.push(nums1[i++]);
        } else {
            merged.push(nums2[j++]);
        }
    }
    
    while (i < nums1.length) merged.push(nums1[i++]);
    while (j < nums2.length) merged.push(nums2[j++]);
    
    const n = merged.length;
    if (n % 2 === 0) {
        return (merged[n/2 - 1] + merged[n/2]) / 2;
    } else {
        return merged[Math.floor(n/2)];
    }
};

/**
 * Kth element approach
 */
var findMedianSortedArrays_kth = function(nums1, nums2) {
    const total = nums1.length + nums2.length;
    
    function findKthElement(k) {
        let i = 0, j = 0;
        
        while (k > 1) {
            const half = Math.floor(k / 2);
            const i_advance = Math.min(half, nums1.length - i);
            const j_advance = Math.min(half, nums2.length - j);
            
            if (i_advance === 0) {
                j += k;
                return nums2[j - 1];
            }
            if (j_advance === 0) {
                i += k;
                return nums1[i - 1];
            }
            
            if (nums1[i + i_advance - 1] < nums2[j + j_advance - 1]) {
                i += i_advance;
                k -= i_advance;
            } else {
                j += j_advance;
                k -= j_advance;
            }
        }
        
        if (i >= nums1.length) return nums2[j];
        if (j >= nums2.length) return nums1[i];
        return Math.min(nums1[i], nums2[j]);
    }
    
    if (total % 2 === 1) {
        return findKthElement(Math.floor(total / 2) + 1);
    } else {
        return (findKthElement(total / 2) + findKthElement(total / 2 + 1)) / 2;
    }
};
