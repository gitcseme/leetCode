class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode* tortoise = head->next;
        ListNode* hear = head;
        
        while (tortoise != NULL && tortoise->next != NULL && hear != NULL) {
            if (hear == tortoise)
                return true;
            
            tortoise = tortoise->next->next;
            hear = hear->next;
        }
        
        return false;
    }
};
