// class Solution {
// public:
//     string reverseParentheses(string s) {
//         string res = "";
//         stack<char> stk;
//         int idx = 0;

//         string ss = "";

//         while (idx < s.size() && s[idx] != '(') ss += s[idx++];

//         for (;idx <s.size(); idx++) {
//             if (s[idx] == ')') {
//                 while (!stk.empty() && stk.top() != '(') {
//                     char top = stk.top();
//                     if (top == '(') continue;
//                     res += top;
//                     stk.pop();
//                 }

//                 if (!stk.empty()) stk.pop();
//                 if (stk.empty()) break;

//                 if (!stk.empty()) {
//                     for (char cc: res) stk.push(cc);
//                     res = "";
//                 }
//             } else stk.push(s[idx]);
//         }

//         res = ss + res;
//         for (;idx < s.size(); idx++) {
//             if (s[idx] == ')' || s[idx] == ')') continue;
//             res += s[idx];
//         }

//         return res;
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<char> stk;
        int idx = 0;

        while (idx < s.size() && s[idx] != '(') {
            res += s[idx++];
        }

        for (; idx < s.size(); idx++) {
            if (s[idx] == ')') {
                string temp = "";
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                if (!stk.empty()) stk.pop();

                for (char cc : temp) {
                    stk.push(cc);
                }
            } else {
                stk.push(s[idx]);
            }
        }

        string final_res = "";
        while (!stk.empty()) {
            final_res = stk.top() + final_res;
            stk.pop();
        }

        res += final_res;

        return res;
    }
};
