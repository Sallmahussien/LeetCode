class Solution {
private:
    bool canPlaceBalls(vector<int>& position, int m, int minDist) {
        int count = 1; //no of balls at the begining
        int prevPosition = position[0];  //postion of the first ball

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - prevPosition >= minDist) {
                count += 1; //I placed another ball
                prevPosition = position[i];
                if (count == m) return true;
            }
        }

        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int left = 1;
        int right = position[n-1] - position[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlaceBalls(position, m, mid)) left = mid + 1; 
            else right = mid - 1;
        }

        return right;
    }
};