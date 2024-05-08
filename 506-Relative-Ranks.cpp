class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted_score(score.begin(), score.end());
        sort(sorted_score.begin(), sorted_score.end(), greater<int>());
        
        unordered_map<int, string> rank_map;
        vector<string> medals = {\Gold Medal\, \Silver Medal\, \Bronze Medal\};

        for (int i = 0; i < sorted_score.size(); ++i) {
            if (i < 3) {
                rank_map[sorted_score[i]] = medals[i];
            } else {
                rank_map[sorted_score[i]] = to_string(i + 1);
            }
        }

        vector<string> res;
        for (int s : score) {
            res.push_back(rank_map[s]);
        }
        
        return res;
    }
};