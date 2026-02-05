class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        int[] h = new int[hFences.length + 2];
        System.arraycopy(hFences, 0, h, 0, hFences.length);
        h[h.length - 2] = 1;
        h[h.length - 1] = m;
        Arrays.sort(h);

        int[] v = new int[vFences.length + 2];
        System.arraycopy(vFences, 0, v, 0, vFences.length);
        v[v.length - 2] = 1;
        v[v.length - 1] = n;
        Arrays.sort(v);

        Set<Integer> hGaps = new HashSet<>();
        for (int i = 0; i < h.length; i++) {
            for (int j = i + 1; j < h.length; j++) {
                hGaps.add(h[j] - h[i]);
            }
        }

        long maxSide = -1;
        for (int i = 0; i < v.length; i++) {
            for (int j = i + 1; j < v.length; j++) {
                int currentGap = v[j] - v[i];
                if (hGaps.contains(currentGap)) {
                    maxSide = Math.max(maxSide, currentGap);
                }
            }
        }

        if (maxSide == -1) return -1;

        return (int) ((maxSide * maxSide) % 1000000007);
    }
}