class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();

        for (String str : strs) {
            String sortedStr = sortStr(str);

            if (!map.containsKey(sortedStr)) {
                map.put(sortedStr, res.size());
                res.add(new ArrayList());
            }

            res.get(map.get(sortedStr)).add(str);
        }

        return res;
    }

    private String sortStr(String str) {
        char[] s = str.toCharArray();
        Arrays.sort(s);
        return new String(s);
    }
}