class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;

        for (string log : logs) {
            if (log == "./") continue;
            else if (log == "../") {
                if (!stk.empty()) stk.pop();
            } else {
                stk.push(log);
            }

        }


        return stk.size();
    }
};