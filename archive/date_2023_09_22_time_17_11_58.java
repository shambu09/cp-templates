import java.util.*;

class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();

        Scanner scanner = new Scanner(System.in);
        String sa = scanner.nextLine();
        scanner.close();

        System.out.println(solution.lengthOfLongestSubstring(sa));
    }

    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> count = new HashMap<Character, Integer>();
        int left = 0;
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (count.containsKey(c)) {
                left = Math.max(left, count.get(c) + 1);
            }

            count.put(c, i);
            res = Math.max(res, i - left + 1);
        }

        return res;
    }
}