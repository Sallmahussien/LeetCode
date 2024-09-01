class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_set<int> fruits_basket;
        int res = 0;
        int l = 0, r = 0;

        for (; r < fruits.size(); r++) {
            if (fruits_basket.size() < 2) {
                fruits_basket.insert(fruits[r]);
            } else if (!fruits_basket.count(fruits[r])) {
                // here i want set to have two elements me, and number that previous me, so how can i do that??


                res = max(res, r-l);
                int fruit_val = fruits[r-1];
                int idx = r - 2;

                while (idx > 0 && fruit_val == fruits[idx]) {
                    idx--;
                }

                fruits_basket.erase(fruits[idx]);
                l = idx+1;

                fruits_basket.insert(fruits[r]);
            }
        }

        cout << l << endl;
        cout << r << endl;

        res = max(res, r - l);


        return res;
    }
};