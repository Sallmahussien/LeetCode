class Solution {
public:
    string countOfAtoms(string formula) {
        int idx = 0;
        stack<pair<string, int>> stk;

        while (idx < formula.size()) {
            if (formula[idx] == '(') {
                stk.push({\(\, 0});
                idx++;
            } else if (formula[idx] == ')') {
                vector<pair<string, int>> v;
                while (!stk.empty() && stk.top().first != \(\) {
                    v.push_back(stk.top());
                    stk.pop();
                }
                if (!stk.empty() && stk.top().first == \(\) stk.pop();
                idx++;

                string count = \\;
                while (idx < formula.size() && isdigit(formula[idx])) {
                    count += formula[idx];
                    idx++;
                }

                int real_count = count.empty() ? 1 : std::stoi(count);

                for (int i = 0; i < v.size(); i++) {
                    v[i].second *= real_count;
                    stk.push(v[i]);
                }
            } else {
                string ele_name = \\;
                string ele_count = \\;

                ele_name += formula[idx++];

                while (idx < formula.size() && !isupper(formula[idx]) && formula[idx] != '(' && formula[idx] != ')') {
                    if (isdigit(formula[idx])) ele_count += formula[idx];
                    else ele_name += formula[idx];

                    idx++;
                }

                if (ele_count == \\) ele_count = \1\;

                stk.push({ele_name, stoi(ele_count)});
            }
        }

        unordered_map<string, int> m;
        vector<string> elements;

        while (!stk.empty()) {
            pair<string, int> top_ele = stk.top();
            cout << top_ele.first << endl;
            if (m.count(top_ele.first)) m[top_ele.first] += top_ele.second;
            else {
                m[top_ele.first] = top_ele.second;
                elements.push_back(top_ele.first);
            }
            
            stk.pop();
        }

        sort(elements.begin(), elements.end());
        string res = \\;

        for (auto e : elements) {
            res += e;
            if (m[e] > 1) res += to_string(m[e]);
        }

        return res;
    }
};