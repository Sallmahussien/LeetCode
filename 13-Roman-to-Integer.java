class Solution {
    public int romanToInt(String s) {
         Map<Character, Integer> map = Map.of(
            'I', 1, 'V', 5, 'X', 10, 'L', 50,
            'C', 100, 'D', 500, 'M', 1000
        );

        int ans = 0;
        int curr = 0;
        int next = 0;

        for (int idx = 0; idx < s.length(); idx++) {
            curr = map.get(s.charAt(idx));
            next = idx + 1 < s.length() ? map.get(s.charAt(idx + 1)) : 0;

            if (curr < next) {
                ans += (next - curr);
                idx++;
            } else {
                ans += curr;
            }
        }

        return ans; 
    }
}