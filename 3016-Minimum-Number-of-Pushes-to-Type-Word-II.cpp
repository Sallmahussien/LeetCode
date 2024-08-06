class Solution {
public:
    int minimumPushes(string word) {
       unordered_map<char, int> frequency;
        for (char c : word) {
            frequency[c]++;
        }

        vector<int> frequencies;
        for (const auto& pair : frequency) {
            frequencies.push_back(pair.second);
        }

        sort(frequencies.begin(), frequencies.end(), greater<int>());

        int totalPresses = 0;
        int lettersAssigned = 0;
        int pressesPerKey = 1;

        for (int freq : frequencies) {
            totalPresses += freq * pressesPerKey;
            lettersAssigned++;

            if (lettersAssigned == 8) {
                lettersAssigned = 0;
                pressesPerKey++;
            }
        }

        return totalPresses;
            
    }
};