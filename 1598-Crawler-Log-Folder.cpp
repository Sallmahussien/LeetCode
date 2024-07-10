class Solution {
public:
    int minOperations(vector<string>& logs) {
        // stack<string> stk;

        // for (string log : logs) {
        //     if (log == "./") continue;
        //     else if (log == "../") {
        //         if (!stk.empty()) stk.pop();
        //     } else {
        //         stk.push(log);
        //     }

        // }

        // return stk.size();

        int res = 0;

        for (string log : logs) {
            if (log == "./") continue;
            else if (log == "../") res = max(0, res - 1);
            else res++;
        }

        return res;
    }
};