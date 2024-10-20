class Solution {
private:
    unordered_map<char, bool> exp_val = {
        {'t', true},
        {'f', false}
    };

    unordered_map<char, function<bool(vector<char>)>> ops;

    bool parse_and(vector<char> exps) {
        bool res = true;

        for (char exp : exps) {
            res &= exp_val[exp];
        }

        return res;
    }

    bool parse_or(vector<char> exps) {
        bool res = false;

        for (char exp : exps) {
            cout << exp << endl;
            res |= exp_val[exp];
        }

        return res;
    }

    bool parse_not(vector<char> exps) {
        return !exp_val[exps[0]];
    }

public:
    Solution() {
        // Initialize the map with lambdas capturing `this`
        ops['&'] = [this](vector<char> exps) { return this->parse_and(exps); };
        ops['|'] = [this](vector<char> exps) { return this->parse_or(exps); };
        ops['!'] = [this](vector<char> exps) { return this->parse_not(exps); };
    }

    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (char exp : expression) {
            if (exp == ',') continue;

            if (exp == ')') {
                vector<char> exps;

                while (stk.top() != '(') {
                    exps.push_back(stk.top());
                    stk.pop();
                }

                // pop the opening brackets
                stk.pop();
                char sign = stk.top();
                //pop sign
                stk.pop();
                stk.push(ops[sign](exps) ? 't' : 'f');
            } else {
                stk.push(exp);
            }
        }

        return stk.top() == 't' ? true : false;
    }
};