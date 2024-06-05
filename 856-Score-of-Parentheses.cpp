class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> score;
        score.push(0);

        for (char c : s) {
            if (c == '(') score.push(0);
            else {
                int top = score.top();
                score.pop();
                if (top == 0) {
                    score.top() += 1;
                } else {
                    score.top() += (top * 2);
                }
            }
        }

        return score.top();   
    }
};