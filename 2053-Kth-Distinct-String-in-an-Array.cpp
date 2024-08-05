class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq_arr;

        for (string s : arr) freq_arr[s]++;

        vector<string> distinct_strs;
        for (string s : arr) {
            if (freq_arr[s] == 1) distinct_strs.push_back(s);
        }

        return distinct_strs.size() >= k ? distinct_strs[k-1] : "";
        
    }
};