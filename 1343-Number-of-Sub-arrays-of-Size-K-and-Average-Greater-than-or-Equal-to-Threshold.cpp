class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int sum = 0;

        for (int j = 0; j < k; j++) {
            sum += arr[j];
        }

        if (sum/k >= threshold) res += 1;

        for (int i = 1; i <= arr.size() - k; i++) {
            sum += arr[i+k-1] - arr[i-1];
            int average = sum / k;
            if (average >= threshold) res += 1;
        }

        return res;
    }
};