class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // vector<int> sorted_heights = heights;
        // sort(sorted_heights.begin(), sorted_heights.end());
        // int res = 0;

        // for (int i = 0; i < heights.size(); i++) {
        //     if (heights[i] != sorted_heights[i]) res += 1;
        // }


        vector<int> count(100);
        for (int height : heights) {
            count[height-1]++;
        }

        int res = 0;
        int idx = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < count[i]; j++) {
                if (heights[idx++] != i+1) res++;
            }
        }

        return res;
    }
};