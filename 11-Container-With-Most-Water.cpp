class Solution {
public:
    int maxArea(vector<int>& height) {
        // int area = INT_MIN;

        // for (int i = 0; i < height.size(); i++) {
        //     for (int j = i+1; j < height.size(); j++) {
        //         area = max(area, (j-i) * min(height[i], height[j]));
        //     }
        // }

        // return area;

        int l = 0, r = height.size()-1;
        int area = INT_MIN;

        while (l < r) {
            area = max(area, (r-l) * min(height[l], height[r]));

            if (height[l] < height[r]) l++;
            else r--;
        }

        return area;
    }
};