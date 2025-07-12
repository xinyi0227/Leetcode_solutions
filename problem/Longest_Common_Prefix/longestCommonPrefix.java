class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";

        int minLen = strs[0].length();
        for (String s : strs) {
            minLen = Math.min(minLen, s.length());
        }

        for (int i = 0; i < minLen; i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }

        return strs[0].substring(0, minLen);
    }

    public String longestCommonPrefix_horizontal(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";

        String prefix = strs[0];

        for (int i = 1; i < strs.length; i++) {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() &&
                    prefix.charAt(j) == strs[i].charAt(j)) {
                j++;
            }
            prefix = prefix.substring(0, j);

            if (prefix.isEmpty())
                return "";
        }

        return prefix;
    }

    public String longestCommonPrefix_divide_conquer(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";

        return divideConquer(strs, 0, strs.length - 1);
    }

    private String divideConquer(String[] strs, int l, int r) {
        if (l == r)
            return strs[l];

        int mid = (l + r) / 2;
        String leftPrefix = divideConquer(strs, l, mid);
        String rightPrefix = divideConquer(strs, mid + 1, r);

        return commonPrefix(leftPrefix, rightPrefix);
    }

    private String commonPrefix(String left, String right) {
        int minLen = Math.min(left.length(), right.length());
        for (int i = 0; i < minLen; i++) {
            if (left.charAt(i) != right.charAt(i)) {
                return left.substring(0, i);
            }
        }
        return left.substring(0, minLen);
    }
}
