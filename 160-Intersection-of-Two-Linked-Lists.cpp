/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == headB) return headA;

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        unordered_set<ListNode*> addresses;

        while (curr1 || curr2) {
            if (curr1) {
                if (addresses.count(curr1)) return curr1;
                addresses.insert(curr1);
                curr1 = curr1->next;
            }

            if (curr2) {
                if (addresses.count(curr2)) return curr2;
                addresses.insert(curr2);
                curr2 = curr2->next;
            }
        }

        return nullptr;
    }
};
