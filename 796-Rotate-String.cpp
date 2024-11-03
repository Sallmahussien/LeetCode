class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string str = s + s;
        int n = goal.size();
        for (int i = 0; i < str.size() - n + 1; i++) {
            if (str.substr(i, n) == goal) return true;
        }

        return false;   
    }
};