class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        int prefix_length = 0;

        for (int idx = 0; idx < strs[0].size(); idx++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].empty() || idx >= strs[i].size() || strs[i][idx] != strs[0][idx]) 
                    return strs[0].substr(0, prefix_length);
            }

            prefix_length++;
        }

       return strs[0].substr(0, prefix_length);
    }
};