class Solution {
public:
    int numTeams(vector<int>& rating) {
        // brute force solution will be three loops
        // int res = 0;

        // for (int i = 0; i < rating.size(); i++) {
        //     for (int j = i+1; j < rating.size(); j++) {
        //         if (rating[i] > rating[j] || rating[i] < rating[j]) {
        //             for (int k = j+1; k < rating.size(); k++) {
        //                 if (rating[i] - rating[j] < 0 && rating[k] > rating[j]) {
        //                     res++;
        //                 } else if (rating[i] - rating[j] > 0 && rating[k] < rating[j]) {
        //                     res++;
        //                 }
        //             }
        //         }
        //     }

        // }

        // return res;

        // count number that smaller than middle at left, hight than it at right

        int res = 0;
        for (int j = 1; j < rating.size()-1; j++) {
            int less_ratings1 = 0;
            int higher_ratings1 = 0;

            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) less_ratings1++;
                if (rating[i] > rating[j]) higher_ratings1++;
            }

            int less_ratings2 = 0;
            int higher_ratings2 = 0;
            for (int k = j + 1; k < rating.size(); k++) {
                if (rating[k] < rating[j]) less_ratings2++;
                if (rating[k] > rating[j]) higher_ratings2++;
            }

            cout << "less1: " << less_ratings1 << endl;
            cout << "higher1: " << higher_ratings1 << endl;

            cout << "less2: " << less_ratings1 << endl;
            cout << "higher2: " << higher_ratings1 << endl;

            

            res += (less_ratings1 * higher_ratings2) + (less_ratings2 * higher_ratings1);
        }

        return res;
    }
};