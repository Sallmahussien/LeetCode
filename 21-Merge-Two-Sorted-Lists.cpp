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

        ListNode* prev1 = nullptr;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while (curr2) {
            while (curr1 && curr1->val <= curr2->val) {
                prev1 = curr1;
                curr1 = curr1->next;
            }

            ListNode* temp = curr2;
            curr2 = curr2->next;
            if (prev1) {
                prev1->next = temp;
                prev1 = prev1->next;
            }
            else {
                list1 = temp;
                prev1 = temp;
            }

            temp->next = curr1;
        }

        return list1;
    }
};