class Solution {
    vector<ListNode*> nodes;
public:
    Solution(ListNode* head) {
        while(head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        int length = nodes.size();
        int random = rand() % length;
        
        return nodes[random]->val;
    }
};
