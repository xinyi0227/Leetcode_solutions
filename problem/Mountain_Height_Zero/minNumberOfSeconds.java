class Solution {
    public long minNumberOfSeconds(int height, int[] times) {
        long lo = 1, hi = (long) 1e16;

        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            long tot = 0;
            for (int t : times) {
                tot += (long) (Math.sqrt((double) mid / t * 2 + 0.25) - 0.5);
                if (tot >= height) break;
            }
            if (tot >= height)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
}