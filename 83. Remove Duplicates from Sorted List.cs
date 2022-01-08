public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(105);
        ListNode current = dummy;
        
        if (head == null) return head;
        current.next = head;
        
        while (head != null) {
            
            while (head.next != null && head.val == head.next.val) {
                head = head.next;
            }
            
            current.next = head;
            current = current.next;
            head = head.next;
        }
        
        return dummy.next;
    }
}
