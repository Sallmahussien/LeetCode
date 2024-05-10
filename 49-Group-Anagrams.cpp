class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // answer one
        // map<string, vector<string>> anagram_map;
        // vector<vector<string>> result;

        // for (string str: strs) {
        //     string sorted_str = str;
        //     sort(sorted_str.begin(), sorted_str.end());
        //     anagram_map[sorted_str].push_back(str);
        // }

        // for (const auto& pair : anagram_map) {
        //     result.push_back(pair.second);
        // }

        // answer two
        map<vector<int>, vector<string>> anagram_map;
        vector<vector<string>> result;
        for (string str: strs) {
            vector<int> count(26, 0);
            for (char c: str) {
                int idx = c - 'a';
                count[idx]++;
            }

            anagram_map[count].push_back(str);
        }

        for (auto &pair: anagram_map) {
            result.push_back(pair.second);
        }

        return result;
    }
};