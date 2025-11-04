class Solution {
    public int largestAltitude(int[] gain) {
        int alt = 0;
        int best = 0;

        for (int g : gain) {
            alt += g; 
            if (alt > best) {
                best = alt;
            }
        }

        return best;
    }
}