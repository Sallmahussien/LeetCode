class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());

        long long score = 0;

        while (k--) {
            int top = q.top();
            q.pop();
    
            score += top;

            q.push(ceil(top / 3.0));
        }

        return score;
    }
};