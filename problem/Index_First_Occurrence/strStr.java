class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty())
            return 0;

        int haystackLen = haystack.length();
        int needleLen = needle.length();

        for (int i = 0; i <= haystackLen - needleLen; i++) {
            if (haystack.substring(i, i + needleLen).equals(needle)) {
                return i;
            }
        }

        return -1;
    }

    public int strStr_builtin(String haystack, String needle) {
        if (needle.isEmpty())
            return 0;

        return haystack.indexOf(needle);
    }

    public int strStr_manual(String haystack, String needle) {
        if (needle.isEmpty())
            return 0;

        int haystackLen = haystack.length();
        int needleLen = needle.length();

        for (int i = 0; i <= haystackLen - needleLen; i++) {
            boolean match = true;
            for (int j = 0; j < needleLen; j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }

        return -1;
    }

    public int strStr_kmp(String haystack, String needle) {
        if (needle.isEmpty())
            return 0;

        int[] lps = new int[needle.length()];
        int len = 0;
        int i = 1;

        while (i < needle.length()) {
            if (needle.charAt(i) == needle.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;

        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            }

            if (j == needle.length()) {
                return i - j;
            } else if (i < haystack.length() && haystack.charAt(i) != needle.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
}
