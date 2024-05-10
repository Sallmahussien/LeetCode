class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int arr_size = arr.size();
        vector<int> ans(arr_size);
        int max = INT_MIN;

        ans[arr_size - 1] = -1;
        for(int i = arr_size - 2; i >= 0; i--) {
            if (arr[i + 1] > max) max = arr[i + 1];

            ans[i] = max;
        }
        
        // for (int i = 0; i < arr_size - 1; i++) { 
        //     int max = arr[i + 1];
        //     for (int j = i + 2; j < arr_size; j++) {
                
        //         if (arr[j] > max) {
        //             max = arr[j];
        //         }
        //     }

        //     ans[i] = max;
        //     cout<< ans[i] << endl;

        // }

        // ans[arr_size - 1] = -1;

        return ans;
    }
};