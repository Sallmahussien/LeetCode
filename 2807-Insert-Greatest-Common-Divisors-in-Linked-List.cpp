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
    int gcd (int a, int b) {
        if (a < b) swap(a, b);
        int rem = a % b;

        while (rem != 0) {
            a = b;
            b = rem;
            rem = a % b;
        }

        return b;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr->next) {
            int gcd_val = gcd(curr->val, curr->next->val);
            ListNode* new_node = new ListNode(gcd_val, curr->next);
            curr->next = new_node;
            curr = new_node->next;;
        }

        return head;
    }
};