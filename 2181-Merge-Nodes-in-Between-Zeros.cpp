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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* res = nullptr;
        ListNode* curr = res;

        while (fast) {
            int sum = 0;
            while (fast && fast->val != 0) {
                sum += fast->val;
                fast = fast->next;
            }

            ListNode* new_node = new ListNode(sum);
            if (!curr) res = new_node;
            else curr->next = new_node;
            curr = new_node;

            if (fast) fast = fast->next;
        }

        return res;
        
    }
};