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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* fast = head, *slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev2 = nullptr, *curr2 = slow->next;
        slow->next = nullptr;

        while(curr2) {
            ListNode* tmp = curr2;
            curr2 = curr2->next;
            tmp->next = prev2;
            prev2 = tmp;
        }

        curr2 = prev2;
        ListNode* curr1 = head;

        while(curr1 && curr2) {
            ListNode* tmp1 = curr1;
            ListNode* tmp2 = curr2;
            curr1 = curr1->next;
            curr2 = curr2->next;
            tmp1->next = tmp2;
            tmp2->next = curr1;
        }
    }
};