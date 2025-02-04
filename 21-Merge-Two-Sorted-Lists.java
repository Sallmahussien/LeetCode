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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        
        ListNode curr1 = list1;
        ListNode curr2 = list2;

        ListNode theList = null;
        ListNode curr = null;

        while (curr1 != null && curr2 != null) {
            if (curr1.val < curr2.val) {
                if (theList == null) {
                    theList = curr1;
                } else {
                    curr.next = curr1;
                }

                curr = curr1;
                curr1 = curr1.next;

            } else {
                if (theList == null) {
                    theList = curr2;
                } else {
                    curr.next = curr2;
                }

                curr = curr2;
                curr2 = curr2.next;
            }
        }

        if (curr1 != null) curr.next = curr1;
        if (curr2 != null) curr.next = curr2;

        return theList;
    }
}