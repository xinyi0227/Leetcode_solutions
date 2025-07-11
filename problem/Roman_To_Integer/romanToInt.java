class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> romanValues = new HashMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && romanValues.get(s.charAt(i)) < romanValues.get(s.charAt(i + 1))) {
                total += romanValues.get(s.charAt(i + 1)) - romanValues.get(s.charAt(i));
                i++;
            } else {
                total += romanValues.get(s.charAt(i));
            }
        }

        return total;
    }

    public int romanToInt_pattern(String s) {
        Map<String, Integer> patterns = new HashMap<>();
        patterns.put("IV", 4);
        patterns.put("IX", 9);
        patterns.put("XL", 40);
        patterns.put("XC", 90);
        patterns.put("CD", 400);
        patterns.put("CM", 900);

        Map<Character, Integer> values = new HashMap<>();
        values.put('I', 1);
        values.put('V', 5);
        values.put('X', 10);
        values.put('L', 50);
        values.put('C', 100);
        values.put('D', 500);
        values.put('M', 1000);

        int total = 0;
        int i = 0;

        while (i < s.length()) {
            if (i + 1 < s.length()) {
                String twoChar = s.substring(i, i + 2);
                if (patterns.containsKey(twoChar)) {
                    total += patterns.get(twoChar);
                    i += 2;
                    continue;
                }
            }
            total += values.get(s.charAt(i));
            i++;
        }

        return total;
    }
}
