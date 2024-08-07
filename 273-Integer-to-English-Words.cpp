class Solution {
private:
    vector<string> splitNum(int num) {
        vector<string> res;

        while (num > 0) {
            string word = to_string(num % 1000);

            while (word.size() != 3) word = '0' + word;
            res.push_back(word);
            num /= 1000;

        }

        return res;
    }

    string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        if (first == string::npos) return \\;
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, last - first + 1);
    }
public:
    string numberToWords(int num) {
        if (num == 0) return \Zero\;

         vector<string> words = splitNum(num);
        map<char, string> digits = {
            {'1', \One\},
            {'2', \Two\},
            {'3', \Three\},
            {'4', \Four\},
            {'5', \Five\},
            {'6', \Six\},
            {'7', \Seven\},
            {'8', \Eight\},
            {'9', \Nine\}
        };

        map<char, string> teens = {
            {'0', \Ten\},
            {'1', \Eleven\},
            {'2', \Twelve\},
            {'3', \Thirteen\},
            {'4', \Fourteen\},
            {'5', \Fifteen\},
            {'6', \Sixteen\},
            {'7', \Seventeen\},
            {'8', \Eighteen\},
            {'9', \Nineteen\}
        };

        map<char, string> tens = {
            {'2', \Twenty\},  
            {'3', \Thirty\},
            {'4', \Forty\},
            {'5', \Fifty\},
            {'6', \Sixty\},
            {'7', \Seventy\},
            {'8', \Eighty\},
            {'9', \Ninety\}      
        };

        vector<string> h = {\\, \Thousand\, \Million\, \Billion\};

        string res = \\;

        for (int i = 0; i < words.size(); i++) {
            string s = \\;
            string word = words[i];

            // Hundreds place
            if (word[0] != '0') {
                s += digits[word[0]];
                s += \ Hundred \;
            }


            // tens and teens place
            if (word[1] != '0') {
                s += word[1] == '1' ? teens[word[2]] : tens[word[1]];
                s += \ \;
            }

            if (word[1] != '1' && word[2] != '0') {
                s += digits[word[2]] + \ \;
            }

            if (!s.empty() && !h[i].empty()) s += h[i] + \ \;

            res = s + res;
        }

        return trim(res);
    }
};