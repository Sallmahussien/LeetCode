/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null;
        ListNode curr = null;
        ListNode curr1 = l1;
        ListNode curr2 = l2;
        int carry = 0;

        while (curr1 != null || curr2 != null || carry != 0) {
            int n1 = curr1 != null ? curr1.val : 0;
            int n2 = curr2 != null ? curr2.val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;

            ListNode newNode = new ListNode(sum % 10);

            if (curr == null) {
                head = newNode;
                curr = newNode;
            } else {
                curr.next = newNode;
                curr = curr.next;
            }

            if (curr1 != null) curr1 = curr1.next;
            if (curr2 != null) curr2 = curr2.next;
        }

        return head;
    }
}