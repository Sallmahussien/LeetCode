class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> person;

        for (int i = 0; i < names.size(); i++) person[heights[i]] = names[i];

        sort(heights.begin(), heights.end(), greater<int>());

        vector<string> res;
        for (int height : heights) res.push_back(person[height]);

        return res;
    }
};