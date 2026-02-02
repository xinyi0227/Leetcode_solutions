class Solution {
    public double separateSquares(int[][] squares) {
        double l = Double.MAX_VALUE, r = Double.MIN_VALUE;
        for (int[] s : squares) {
            l = Math.min(l, (double)s[1]);
            r = Math.max(r, (double)s[1] + s[2]);
        }

        for (int i = 0; i < 100; i++) {
            double mid = l + (r - l) / 2;
            if (validate(squares, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }

    private boolean validate(int[][] squares, double mid) {
        double below = 0, above = 0;
        for (int[] s : squares) {
            double y0 = s[1], side = s[2], y1 = y0 + side;
            below += Math.max(0.0, (Math.min(y1, mid) - y0) * side);
            above += Math.max(0.0, (y1 - Math.max(mid, y0)) * side);
        }
        return below >= above;
    }
}