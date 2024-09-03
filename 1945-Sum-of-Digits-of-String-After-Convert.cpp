class Solution {
public:
    int getLucky(string s, int k) {
        string str_repr = "";

        for (char c : s) {
            str_repr += to_string(c - 'a' + 1);
        }

        while (k--) {
            int sum = 0;
            for (char c : str_repr) {
                sum += c - 48;
            }

            str_repr = to_string(sum);
        }

        return stoi(str_repr);
    }
};