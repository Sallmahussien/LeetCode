class Solution {
    public int maximumLength(String s) {
        int res = -1;
        Map<String, Integer> freqArr = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            String str = "";
            for (int j = i; j < s.length(); j++) {
                str += s.charAt(j);

                if (str.length() > 1 && s.charAt(j) != s.charAt(j-1)) break;

                freqArr.put(str, (freqArr.containsKey(str) ? freqArr.get(str) : 0) + 1);

                if (freqArr.get(str) >= 3) {
                    System.out.println(str);
                    res = Math.max(res, str.length());
                }
            }
        }

        return res;
    }
}