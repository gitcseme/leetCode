public class Solution {
    public ListNode ReverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode current = head.next, prev = head, temp = head.next;
        ListNode headPointer = head;
        
        while (current != null) {
            temp = current.next;
            current.next = prev;
            
            prev = current;
            current = temp;
        }
        
        headPointer.next = null; // set heal as tail now.
        
        return prev;
    }
}
