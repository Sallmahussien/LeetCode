class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq_arr;

        for (int n : target) freq_arr[n]++;

        for (int n : arr) {
            if (freq_arr[n] == 0) return false;

            freq_arr[n]--;
        }

        return true;
    }
};