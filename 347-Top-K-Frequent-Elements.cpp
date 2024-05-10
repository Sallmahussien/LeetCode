class Solution {
public:
    static bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq_arr;
        vector<pair<int, int>> frq_vec;
        vector<int> ans;

        for (int num: nums) freq_arr[num]++;

        for(auto& pair: freq_arr) frq_vec.push_back(pair);

        sort(frq_vec.begin(), frq_vec.end(), sortByVal);
        
        while(k > 0) {
            ans.push_back(frq_vec[k-1].first);
            k--;
        }
        
        return ans;
    }
};