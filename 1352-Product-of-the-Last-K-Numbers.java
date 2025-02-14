class ProductOfNumbers {
    List<Integer> arr = null;
    int lastZeroIndex;

    public ProductOfNumbers() {
        arr = new ArrayList<>();
        arr.add(1);

        lastZeroIndex = -1;
    }
    
    public void add(int num) {
        int n = arr.size();

        if (num == 0) {
            arr.add(1);
            lastZeroIndex = n;
        } else {
           arr.add(num * arr.get(n - 1));
        }
    }
    
    public int getProduct(int k) {
        int n = arr.size();
        int idx = n - k - 1;

        if (lastZeroIndex >= 0 && lastZeroIndex > idx) return 0;

        return arr.get(n-1) / arr.get(idx);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */