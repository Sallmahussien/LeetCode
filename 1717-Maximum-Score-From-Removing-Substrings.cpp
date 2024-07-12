class Solution {
private:
    int get_score(string& s, string substr, int score) {
        int final_score { };
        stack<char> stk;

        for (char c : s) {
            if (!stk.empty() && string(1, stk.top()) + c == substr) {
                final_score += score;
                stk.pop();   
            } else stk.push(c);
        }

        string remaining_str = "";

        while (!stk.empty()) {
            remaining_str += stk.top();
            stk.pop();
        }

        reverse_str(remaining_str);
        s.assign(remaining_str.begin(), remaining_str.end());

        return final_score;
    }

    void reverse_str(string& str) {
        int l = 0, r = str.size()-1;

        while (l < r) swap(str[l++], str[r--]);
    }

public:
    int maximumGain(string s, int x, int y) {
        // x => ab
        // y => ba
        int score = 0;
        pair<int, string> score_str;
        
        if (x > y) {
            score += get_score(s, "ab", x);
            score += get_score(s, "ba", y);
        } else {
            score += get_score(s, "ba", y);
            score += get_score(s, "ab", x);
        }

        return score;
    }
};
