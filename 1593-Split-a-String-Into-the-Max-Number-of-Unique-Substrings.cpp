class Solution {
private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.length()) {
            return seen.size();
        }
        
        int max_count = 0;
        
        for (int i = start + 1; i <= s.length(); ++i) {
            string substring = s.substr(start, i - start);
            
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                max_count = max(max_count, backtrack(s, i, seen));
                seen.erase(substring);
            }
        }
        
        return max_count;
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }
};