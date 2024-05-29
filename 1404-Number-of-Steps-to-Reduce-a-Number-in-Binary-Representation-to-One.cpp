class Solution {
private:
    void add_one(string & s) {
        int n = s.size()-1;

        for (int i = n; i >= 0; i--) {
            if (s[i] == '0') {
                s[i] = '1';
                return;
            }
            else s[i] = '0';
        }

        s = '1' + s;
    }
public:
    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            if (s.back() == '0') {
                // even number, divide by 2, right shift, remove the last bit
                s.pop_back();
            } else {
                // odd number, add 1
                add_one(s);
            }

            steps += 1;
            size_t pos = s.find_first_not_of('0');
            s = s.substr(pos);
        }

        return steps;
    }
};