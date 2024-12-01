class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> setNums = new HashSet<>();

        for (int n : arr) {
            if (setNums.contains(n * 2) || (n % 2 == 0 && setNums.contains(n / 2))) {
                return true;
            }

            setNums.add(n);
        }

    

        return false;
        
    }
}