class Solution {
private:
    vector<int> candidates;
    int target;
    vector<vector<int>> res;

    void dfs(int i, vector<int>& curr, int total) {
        if (total == target) {
            res.push_back(curr);
            return;
        }

        if (total > target || i == candidates.size()) return;

        // include candidates[i]
        curr.push_back(candidates[i]);
        dfs(i+1, curr, total + candidates[i]);

        // skip candidates[i]
        curr.pop_back();
        // not include duplicate numbers
        while (i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        dfs(i+1, curr, total);
    }


    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       this->target = target;
       this->candidates = candidates;

        sort(this->candidates.begin(), this->candidates.end());

        vector<int> curr;
        dfs(0, curr, 0);

        return res;
    }
};