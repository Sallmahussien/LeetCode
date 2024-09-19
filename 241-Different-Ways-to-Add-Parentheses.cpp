class Solution {
private:
    int compute(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                vector<int> leftPart = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightPart = diffWaysToCompute(expression.substr(i + 1));

                for (int left : leftPart) {
                    for (int right : rightPart) {
                        result.push_back(compute(left, right, c));
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};