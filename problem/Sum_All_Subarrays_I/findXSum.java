class Solution {
    private int find(Map<Integer, Integer> mp, int x) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return b[1] - a[1];
            return b[0] - a[0];
        });
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            pq.offer(new int[]{entry.getValue(), entry.getKey()});
        }
        int sum = 0;
        while (x-- > 0 && !pq.isEmpty()) {
            int[] item = pq.poll();
            sum += item[0] * item[1];
        }
        return sum;
    }
    
    public int[] findXSum(int[] nums, int k, int x) {
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer> v = new ArrayList<>();
        int l = 0, r = 0;
        while (r < nums.length) {
            mp.put(nums[r], mp.getOrDefault(nums[r], 0) + 1);
            while (l < r && r - l + 1 > k) {
                mp.put(nums[l], mp.get(nums[l]) - 1);
                if (mp.get(nums[l]) == 0) {
                    mp.remove(nums[l]);
                }
                l++;
            }
            if (r - l + 1 == k) {
                v.add(find(mp, x));
            }
            r++;
        }
        return v.stream().mapToInt(i -> i).toArray();
    }
}