import java.util.*;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Arrays.sort(arr);
        List<Integer> counts = new ArrayList<>();
        int i = 0;
        while (i < arr.length) {
            int cnt = 1;
            while (i + 1 < arr.length && arr[i] == arr[i + 1]) {
                cnt++;
                i++;
            }
            counts.add(cnt);
            i++;
        }
        Collections.sort(counts);
        for (int j = 1; j < counts.size(); j++) {
            if (Objects.equals(counts.get(j), counts.get(j - 1))) return false;
        }
        return true;
    }
}
