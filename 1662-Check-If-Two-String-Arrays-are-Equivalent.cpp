class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = "";
        string w2 = "";

        for (string w : word1) w1 += w;
        for (string w : word2) w2 += w;

        return w1 == w2;
    }
};