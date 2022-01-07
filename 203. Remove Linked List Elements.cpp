class Solution {
public:
    ListNode* removeElements(ListNode* head, int target) {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        
        while (head != nullptr) {
            while (head != nullptr && head->val == target) {
                head = head->next;
            }
            current->next = head;
            current = current->next;
            if (head != nullptr)
                head = head->next;
        }
        
        return dummy->next;
    }
};
