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
        // int largest_length = 0;
        // int i = 0;
        // int n = s.size();

        // while(i < n) {
        //     char matched_char = s[i];
        //     int len = 1, times = k, idx = i+1;
        //     while((idx < n) && (times > 0 || matched_char == s[idx])) {
        //         len++;
        //         if (matched_char != s[idx]) {
        //             times--;
        //             i = idx;
        //         }
        //         idx++;
        //     }

        //     if (k == 0) i = idx;

        //     if (len > largest_length) largest_length = len;
        //     if (times == k && idx == n) break;
        // }

        // return largest_length;

        int left = 0, right = 0;
        int n = s.size();
        unordered_map<char, int> freq_arr;
        int longest = 0;

        while (right < n) {
            freq_arr[s[right]]++;
            int max_occur = get_max(freq_arr);

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