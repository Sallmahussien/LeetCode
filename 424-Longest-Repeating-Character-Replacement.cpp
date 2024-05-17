class Solution {
private:
    int get_max(const unordered_map<char, int>& m) {
        int max = INT_MIN;
        for (const auto& pair : m) {
            if (pair.second > max) max = pair.second;
        }
        return max;
    }
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int n = s.size();
        unordered_map<char, int> freq_arr;
        int max_occur = 0;
        int longest = 0;

        while (right < n) {
            freq_arr[s[right]]++;
            max_occur = max(max_occur, freq_arr[s[right]]);

            if (right-left+1 - max_occur > k) {
                freq_arr[s[left]]--;
                left++;
            }

            if (right-left+1 > longest) longest = right-left+1;

            right++;
        }

        return longest;   
    }
};