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
    void reverse(ListNode* &head) {
        if (!head || !head->next) return;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {
            if (prev == head) prev->next = nullptr;

            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        head = prev;
    }

    void add_node(ListNode* &head, int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = head;
        head = new_node;
    }

    void doubleHelper(ListNode* curr, int& carry) {
        if (!curr) return;

        doubleHelper(curr->next, carry);
        int double_val = curr->val * 2 + carry;
        curr->val = double_val % 10;
        carry = double_val / 10;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        // revrese two times
        // if (!head) return head;

        // reverse(head);

        // int carry = 0;
        // ListNode* curr = head;

        // while (curr) {
        //     int double_val = (curr->val) * 2 + carry;
        //     curr->val = double_val % 10;
        //     carry = double_val / 10;
        //     curr = curr->next;
        // }

        // reverse(head);

        // if (carry != 0) add_node(head, carry);

        // return head;

        // reverse only once using recursion
        int carry = 0;
        doubleHelper(head, carry);
        if (carry != 0) add_node(head, carry);

        return head;

    }
};