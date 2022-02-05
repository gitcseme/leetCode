class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        else if (lists.size() == 1) {
            return lists[0];
        }

        ListNode* root = lists[0];
        for (int i = 1, len = lists.size(); i < len; ++i) {
            root = _merge(root, lists[i]);
        }
        return root;
    }

    ListNode* _merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        while (l1 != nullptr)
        {
            current->next = l1;
            current = current->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            current->next = l2;
            current = current->next;
            l2 = l2->next;
        }
        
        return dummy->next;
    }
};
