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
    void remove(ListNode* prev, ListNode* curr, ListNode*& head) {
        if (!curr->next) return;

        remove(curr, curr->next, head);

        if (curr->val < curr->next->val) {
            if (!prev) head = curr->next;
            else prev->next = curr->next;
            delete curr;
        }
    }

public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        remove(prev, curr, head);
        return head;
    }
};