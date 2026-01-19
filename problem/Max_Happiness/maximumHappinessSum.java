class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        
        long sum = 0;
        int n = happiness.length;
        
        for (int i = 0; i < k; i++) {
            long x = Math.max(0, happiness[n - 1 - i] - i);
            sum += x;
        }
        
        return sum;
    }
}