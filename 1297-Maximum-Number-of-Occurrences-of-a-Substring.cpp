class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string balloon = \balloon\;
        unordered_map<char, int> freq_arr;

        for (char c: balloon) {
            freq_arr[c] = 0; 
        }

        for (char c: text) {
            if (freq_arr.count(c)) freq_arr[c]++;
        }

        freq_arr['l'] /= 2;
        freq_arr['o'] /= 2;

        int min = INT_MAX;

        for (auto& pair: freq_arr) {
            if (pair.second < min) min = pair.second;
        }

        return min;   
    }
};