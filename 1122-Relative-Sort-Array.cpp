class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        unordered_map<int, int> freq_arr;
        unordered_set<int> arr2_set(arr2.begin(), arr2.end());
        vector<int> notInArr2;

        for (int num : arr1) {
            if (arr2_set.count(num)) freq_arr[num]++;
            else notInArr2.push_back(num);
        }

        for (int num : arr2) {
            for (int i = 0; i < freq_arr[num]; i++) {
                res.push_back(num);
            }
        }

        sort(notInArr2.begin(), notInArr2.end());

        res.insert(res.end(), notInArr2.begin(), notInArr2.end());

        return res;
    }
};