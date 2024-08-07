class Solution {
public:
    int minimumPushes(string word) {
       vector<int> count(26);
       
       for (char c : word) {
        count[c - 'a']++;
       }

       sort(count.begin(), count.end(), greater<int>());

        int res = 0;
       for (int i = 0; i < count.size(); i++) {
        if (count[i] == 0) break;
        res += count[i] * (1 + ((int) i / 8));
       }

       return res;
    }
};