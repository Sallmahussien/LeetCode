/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int l = 0, r = n-1;
        int t = 0, b = m-1;
        ListNode* curr = head;

        while (l <= r && t <= b && curr) {
            // moving from left to right
            for (int j = l; j <= r && curr; j++) {
                res[t][j] = curr->val;
                curr = curr->next;
            }
            t++;

            // moving from top to bottom
            for (int i = t; i <= b && curr; i++) {
                res[i][r] = curr->val;
                curr = curr->next;
            }
            r--;

            // moving from right to left
            for (int j = r; j >= l && curr; j--) {
                cout << j << endl;
                res[b][j] = curr->val;
                curr = curr->next;
            }
            b--;

            // moving from bottom to top
            for (int i = b; i >= t && curr; i--) {
                res[i][l] = curr->val;
                curr = curr->next;
            }
            l++;
        } 

        return res;
    }
};