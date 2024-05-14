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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {
            if (prev->val == curr->val) {
                ListNode* tmp = curr;
                curr = curr->next;
                prev->next = curr;
                delete tmp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;   
    }
};