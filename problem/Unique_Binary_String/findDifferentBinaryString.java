class Solution {
    private String b(int r, int q) {
        StringBuilder t = new StringBuilder();
        if (r == 0) t.append("0");
        while (r != 0) {
            int y = r % 2;
            r = r / 2;
            t.insert(0, y);
        }
        while (t.length() < q) {
            t.insert(0, "0");
        }
        return t.toString();
    }

    public String findDifferentBinaryString(String[] nums) {
        int j = 0;
        java.util.Arrays.sort(nums);
        for (int i = 0; i <= nums.length; i++) {
            String c = b(i, nums[0].length());
            if (j < nums.length && c.equals(nums[j])) {
                j++;
            } else {
                return c;
            }
        }
        return "";
    }
}