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
        ListNode* lastNode = head;
        int len = 1;

        while (lastNode->next) {
            len++;
            lastNode = lastNode->next;
        }

        if (len == n) {
            head = head->next;
            return head;
        }

        if (n > len) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;

        while (curr && len-count != n) {
            count++;
            prev = curr;
            curr = curr->next;
        }

        if (prev) prev->next = curr->next;
        else head = nullptr;

        delete curr;

        return head;
    }
};