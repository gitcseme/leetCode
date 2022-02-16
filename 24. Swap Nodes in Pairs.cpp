class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        
        while (head != nullptr && head->next != nullptr) {
            
            current->next = head->next;
            ListNode* tmp = head->next->next;
            current->next->next = head;
            head->next = tmp;
            
            current = head;
            head = head->next;
        }
        
        return dummy->next;
    }
};
