class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        
        return nodes[(nodes.size()/2)];
    }
};
