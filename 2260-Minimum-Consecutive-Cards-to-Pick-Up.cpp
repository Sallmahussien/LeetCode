class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        unordered_map<int, int> card_pos;

        for (int i = 0; i < cards.size(); i++) {
            if (card_pos.count(cards[i])) {
                res = min(res, i - card_pos[cards[i]] + 1);
            }

            card_pos[cards[i]] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};