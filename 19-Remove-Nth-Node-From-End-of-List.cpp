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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* lastNode = head;
        // int len = 1;

        // while (lastNode->next) {
        //     len++;
        //     lastNode = lastNode->next;
        // }

        // if (len == n) {
        //     head = head->next;
        //     return head;
        // }

        // if (n > len) return head;

        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // int count = 0;

        // while (curr && len-count != n) {
        //     count++;
        //     prev = curr;
        //     curr = curr->next;
        // }

        // if (prev) prev->next = curr->next;
        // else head = nullptr;

        // delete curr;

        // return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* right = dummy;
        ListNode* left = dummy;

        for (int i = 0; i <= n; i++) right = right->next;

        while (right) {
            right = right->next;
            left = left->next;
        }

        ListNode* nodeToDeleted = left->next;
        left->next = left->next->next;

        delete nodeToDeleted;

        head = dummy->next;
        delete dummy;

        return head;
    }
};