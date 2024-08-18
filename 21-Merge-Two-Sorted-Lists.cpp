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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head = nullptr;
        ListNode* curr = head;
        ListNode* curr1 = list1, *curr2 = list2;

        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                if (!head) {
                    head = curr1;
                    curr = head;
                } else {
                    curr->next = curr1;
                    curr = curr->next;
                }

                curr1 = curr1->next;
            } else {
                if (!head) {
                    head = curr2;
                    curr = head;
                } else {
                    curr->next = curr2;
                    curr = curr->next;
                }

                curr2 = curr2->next;
            }
        }

        if (curr1) {
            curr->next = curr1;
        }

        if (curr2) {
            curr->next = curr2;
        }

        return head;
    }
};