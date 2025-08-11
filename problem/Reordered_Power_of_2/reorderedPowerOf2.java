package problem.Reordered_Power_of_2;

public class reorderedPowerOf2 {
    public boolean reorderedPowerOf2(int n) {
        String target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i).equals(target))
                return true;
        }
        return false;
    }

    private String countDigits(int x) {
        char[] digits = Integer.toString(x).toCharArray();
        Arrays.sort(digits);
        return new String(digits);
    }
}
