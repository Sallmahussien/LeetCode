class Solution {
private:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l == r) return;

        int mid = l + (r-l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);

        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> l_sub_arr;
        vector<int> r_sub_arr;

        for (int i = l; i <= mid; i++) l_sub_arr.push_back(nums[i]);
        for (int i = mid+1; i <= r; i++) r_sub_arr.push_back(nums[i]);

        int idx1 = 0; //left sub arr idx
        int idx2 = 0; //right sub arr idx
        int k = l; //idx for the big arr

        while (idx1 < l_sub_arr.size() && idx2 < r_sub_arr.size()) {
            if (l_sub_arr[idx1] < r_sub_arr[idx2]) nums[k++] = l_sub_arr[idx1++];
            else nums[k++] = r_sub_arr[idx2++];
        }

        while (idx1 < l_sub_arr.size()) {
            nums[k++] = l_sub_arr[idx1++];
        }

        while (idx2 < r_sub_arr.size()) {
            nums[k++] = r_sub_arr[idx2++];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        return nums;
    }
};