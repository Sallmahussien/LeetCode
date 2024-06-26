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
    ListNode* reverse_helper(ListNode* curr, ListNode* prev) {
        if (curr == nullptr) {
            return prev;
        }
        
        ListNode* temp = curr;
        curr = curr->next;
        temp->next = prev;
        prev = temp;
        return reverse_helper(curr, prev);
    }

public:
    ListNode* reverseList(ListNode* head) {
        // recursive solution
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        
        // head = reverse_helper(curr, prev);

        // return head;

        // iterative solution
        if (!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        head = prev;
        return head;
    }

};