class Solution {
private:
    static bool is_lower(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first > b.first;
 
        return a.second < b.second;
    }

public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq_arr;
        for (int num : nums) freq_arr[num]++;

        vector<pair<int, int>> sorted_nums(freq_arr.begin(), freq_arr.end());

        sort(sorted_nums.begin(), sorted_nums.end(), is_lower);

        vector<int> res;

        for (auto pair : sorted_nums) {
            for (int i = 0; i < pair.second; i++) res.push_back(pair.first);
        }

        return res;
        
    }
};