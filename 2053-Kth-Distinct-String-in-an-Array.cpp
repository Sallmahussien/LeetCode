class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq_arr;

        for (string s : arr) freq_arr[s]++;

        for (string s : arr) {
            if (freq_arr[s] == 1) k--;

            if (k == 0) return s;
        }

        return "";
    }
};