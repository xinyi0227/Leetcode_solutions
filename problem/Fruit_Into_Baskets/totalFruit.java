class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        int ans = 0;
        int[] basket = { -1, -1 }, cnt = { 0, 0 };
        int lastRun = 0;

        for (int i = 0; i < n; i++) {
            int x = fruits[i];
            if (x == basket[1]) {
                cnt[1]++;
                lastRun++;
            } else if (x == basket[0]) {
                int temp = basket[0];
                basket[0] = basket[1];
                basket[1] = temp;
                temp = cnt[0];
                cnt[0] = cnt[1];
                cnt[1] = temp;
                cnt[1]++;
                lastRun = 1;
            } else {
                basket[0] = basket[1];
                basket[1] = x;
                cnt[0] = lastRun;
                lastRun = 1;
                cnt[1] = 1;
            }
            ans = Math.max(ans, cnt[0] + cnt[1]);
        }
        return ans;
    }
}
