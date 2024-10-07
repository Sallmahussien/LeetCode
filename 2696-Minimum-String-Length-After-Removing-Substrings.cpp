class Solution {
public:
    int minLength(string s) {
        // int idx = 0;

        // while (idx+1 < s.size()) {
        //     string sub_str = s.substr(idx, 2);
        //     if (sub_str == "AB" || sub_str == "CD") {
        //         s.erase(idx, 2);
        //         if (idx > 0) idx--;
        //     } else {
        //         idx++;
        //     }
        // }

        // return s.size();

        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && 
                ((stk.top() == 'A' && c == 'B') || (stk.top() == 'C' && c == 'D'))) {
                stk.pop(); 
            } else {
                stk.push(c);
            }
        }

        return stk.size();
    }
};