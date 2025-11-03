class Solution {
    public int maxOperations(int[] nums, int k) {
        int n = nums.length;
        int i = 0;
        int j = n - 1;
        int count = 0;
        Arrays.sort(nums);
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                count++;
                i++;
                j--;
            }
            if (sum < k) {
                i++;
            }
            if (sum > k) {
                j--;
            }
        }
        return count;
    }
}
