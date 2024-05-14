/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int get_length(ListNode* head) {
        ListNode* curr = head;
        int count = 0;

        while(curr) {
            count++;
            curr = curr->next;
        }

        return count;
    }
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // solution using set
        // if (headA == headB) return headA;

        // ListNode* curr1 = headA;
        // ListNode* curr2 = headB;
        // unordered_set<ListNode*> addresses;

        // while (curr1 || curr2) {
        //     if (curr1) {
        //         if (addresses.count(curr1)) return curr1;
        //         addresses.insert(curr1);
        //         curr1 = curr1->next;
        //     }

        //     if (curr2) {
        //         if (addresses.count(curr2)) return curr2;
        //         addresses.insert(curr2);
        //         curr2 = curr2->next;
        //     }
        // }

        // return nullptr;

        // solution 2
        int len1 = get_length(headA);
        int len2 = get_length(headB);

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        if (len1 > len2) {
            while(len1 != len2) {
                curr1 = curr1->next;
                len1--;
            }
        } else {
            while(len1 != len2) {
                curr2 = curr2->next;
                len2--;
            }
        }

        while (curr1 && curr2) {
            if (curr1 == curr2) return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next; 
        }

        return nullptr;
    }
};
