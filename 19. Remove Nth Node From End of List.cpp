/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
    using fast & slow pointer. move the fast n steps ahead then move both by 1 step untill fast reached to the end
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fptr = dummy;
        ListNode* sptr = dummy;

        while (n-- >= 0) {
            fptr = fptr->next;
        }

        while (fptr != nullptr) {
            fptr = fptr->next;
            sptr = sptr->next;
        }

        ListNode* nodeToDelete = sptr->next;
        sptr->next = nodeToDelete->next;
        delete(nodeToDelete);

        return dummy->next;
    }
};


















