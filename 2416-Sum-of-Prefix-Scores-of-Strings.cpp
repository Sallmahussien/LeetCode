class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {};
        int freq = 0;
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->freq++;
        }
    }

    int getPrefixScore(TrieNode* root, const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            score += node->freq;
        }
        return score;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word : words) {
            insert(root, word);
        }

        vector<int> res(words.size());
        for (int i = 0; i < words.size(); i++) {
            res[i] = getPrefixScore(root, words[i]);
        }

        return res;
    }
};
