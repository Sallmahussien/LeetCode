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
private:
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* curr = head;

        while (curr) {
            len++;
            curr = curr->next;
        }

        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int list_len = getLength(head);
        int min_sub_list_len = list_len / k;
        int remaining_nodes = list_len > k ? list_len % k : 0;
        vector<ListNode*> res(k);
        ListNode* curr = head;
        

        for (int idx = 0; idx < k; idx++) {
            res[idx] = curr;
            for (int i = 0; i < min_sub_list_len-1 && curr; i++) {
                curr = curr->next;
            }

            if (remaining_nodes > 0 && curr) {
                curr = curr->next;
                remaining_nodes--;
            }

            ListNode* tmp = curr;
            if (curr) curr = curr->next;
            if (tmp) tmp->next = nullptr;
        }

        return res;
    }
};