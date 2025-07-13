class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0)
            return 0;

        int slow = 0;
        for (int fast = 1; fast < nums.length; fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    public int removeDuplicates_alternative(int[] nums) {
        if (nums.length == 0)
            return 0;

        int writeIndex = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        return writeIndex;
    }

    public int removeDuplicates_verbose(int[] nums) {
        if (nums.length <= 1)
            return nums.length;

        int uniqueCount = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[uniqueCount - 1]) {
                nums[uniqueCount] = nums[i];
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
}
