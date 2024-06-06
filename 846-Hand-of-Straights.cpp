class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq_arr;

        for (int card : hand) freq_arr[card]++;

        int groupsNum = hand.size() / groupSize;

        for (int card : hand) {
            if (freq_arr[card] == 0) continue;

            for (int i = 0; i < groupSize; i++) {
                int currCard = card + i;
                if (!freq_arr.count(currCard) || freq_arr[currCard] == 0) return false;
                freq_arr[currCard]--;
            }

            groupsNum--;
            if (groupsNum == 0) break;
        }


        return true;
    }
};