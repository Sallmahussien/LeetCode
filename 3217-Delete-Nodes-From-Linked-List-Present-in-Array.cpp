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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (s.count(curr->val)) {
                ListNode* tmp = curr;
                curr = curr->next;
                if (prev) prev->next = curr;
                else head = curr;

                delete tmp;

            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};