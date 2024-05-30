class Solution {
public:
    bool isValid(string str) {
        unordered_map<char, char> brackets = {
            {'[', ']'},
            {'(', ')'},
            {'{', '}'}
        };

        stack<char> stk;

        for (char c: str) {
            if (brackets.count(c)) stk.push(c);
            else {
                if (stk.empty() || brackets[stk.top()] != c) return false;

                stk.pop();
            }
        }

        return stk.empty();
        
    }
};