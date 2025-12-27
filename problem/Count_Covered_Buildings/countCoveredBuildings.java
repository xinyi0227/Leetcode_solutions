import java.util.*;

class Solution {
    static final int SZ = 100001;
    static int[] xMin = new int[SZ], xMax = new int[SZ], yMin = new int[SZ], yMax = new int[SZ];

    public static int countCoveredBuildings(int n, int[][] buildings) {
        int M = 0, N = 0;
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            if (x > M) M = x;
            if (y > N) N = y;
        }

        Arrays.fill(xMin, 0, N + 1, Integer.MAX_VALUE);
        Arrays.fill(yMin, 0, M + 1, Integer.MAX_VALUE);
        Arrays.fill(xMax, 0, N + 1, 0);
        Arrays.fill(yMax, 0, M + 1, 0);

        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            if (x < xMin[y]) xMin[y] = x;
            if (x > xMax[y]) xMax[y] = x;
            if (y < yMin[x]) yMin[x] = y;
            if (y > yMax[x]) yMax[x] = y;
        }

        int cnt = 0;
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            boolean coverX = (xMin[y] < x) & (x < xMax[y]);
            boolean coverY = (yMin[x] < y) & (y < yMax[x]);
            cnt += (coverX & coverY) ? 1 : 0;
        }
        return cnt;
    }
}
