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
    ListNode* getLastNode(ListNode* &list) {
        ListNode* curr = list;

        while (curr->next) {
            curr = curr->next;
        }

        return curr;
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* last2 = getLastNode(list2);
        ListNode* prev = list1;
       
       for (int i = 0; i < a-1; i++) {
        prev = prev->next;
       }

       ListNode* after = prev->next;
       for (int i = a; i < b; i++) {
        after = after->next;
       }

       prev->next = list2;
       last2->next = after->next;

        return list1;
    }
};