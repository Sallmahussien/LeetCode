class Solution {
    public int minimizeXor(int num1, int num2) {
        int num2OnesCount = 0;
        int num1OnesCount = 0;

        while (num2 != 0) {
            if (num2 % 2 == 1) {
                num2OnesCount++;   
            }

            num2 /= 2;
        }

        int[] num1Bits = new int[32];
        int idx = 31;
        int num1Temp = num1;

        while (num1 != 0) {
            if (num1 % 2 == 1) {
                num1OnesCount++;
                num1Bits[idx] = 1;
            }

            idx--;

            num1 /= 2;
        }

        for (int b : num1Bits) {
            System.out.print(b);
        }

        System.out.println();

        if (num1OnesCount == num2OnesCount) {
            return num1Temp;
        }

        if (num2OnesCount > num1OnesCount) {
            
            idx = 31;
            while((num2OnesCount - num1OnesCount) != 0) {
                while (num1Bits[idx] == 1) {
                    idx--;
                }

                num1Bits[idx] = 1;
                num2OnesCount--;
            }
        }

        if (num2OnesCount < num1OnesCount) {
            idx = 0;
            while(idx < 32 && num1Bits[idx] == 0) {
                idx++;
            }

            System.out.println(idx);

            while (idx < 32 && num2OnesCount != 0) {
                if (num1Bits[idx] == 1) {
                    num2OnesCount--;
                }
                idx++; 
            }

            System.out.println(idx);

            for (int i = idx; i < 32; i++) {
                num1Bits[i] = 0;
            }
        }

        String binaryString = Arrays.stream(num1Bits)
                                     .mapToObj(String::valueOf)
                                     .collect(Collectors.joining());
        return Integer.parseInt(binaryString, 2);
    }
}