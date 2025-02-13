class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> list = new ArrayList<>();
        int numRows = rowIndex + 1;

        for (int i = 0; i < numRows; i++) {
            List<Integer> subList = new ArrayList<>();
            subList.add(1);
            
            for (int j = 1; j < i; j++) {
                subList.add(list.get(i-1).get(j-1) + list.get(i-1).get(j));
            }

            if (i > 0) subList.add(1);

            list.add(subList);
        }

        return list.get(rowIndex);
    }
}