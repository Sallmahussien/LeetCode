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
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalLength = getLength(head);
        int basePartSize = totalLength / k;
        int extraNodes = totalLength % k;

        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;

        for (int i = 0; i < k && current; ++i) {
            result[i] = current;
            int partSize = basePartSize + (extraNodes > 0 ? 1 : 0); 

            for (int j = 1; j < partSize; ++j) {
                current = current->next;
            }

            ListNode* nextPartHead = current->next;
            current->next = nullptr;
            current = nextPartHead;
            extraNodes--;
        }

        return result;
    }
};
