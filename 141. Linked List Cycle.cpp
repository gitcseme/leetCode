class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
        
        // Finding cycle starting point
        // slow = head;
        // while (slow != fast) {
        //     slow = slow->next;
        //     fast = fast->next;
        // }

        // cout << slow->val << "\n";
    }
};
