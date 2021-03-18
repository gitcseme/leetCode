#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int a = l1 != NULL ? l1->val : 0;
        int b = l2 != NULL ? l2->val : 0;
        int sum = a + b + carry;
        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry != 0)
        current->next = new ListNode(carry);

    return dummyHead->next;
}


void traverse(ListNode* node) {
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

int main() {
    //FI;

    ListNode* node1 = new ListNode(9);
    ListNode* node2 = new ListNode(9);
    ListNode* node3 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    traverse(node1);
    cout << "\n";

    ListNode* node4 = new ListNode(9);
    ListNode* node5 = new ListNode(9);
    ListNode* node6 = new ListNode(9);
    node4->next = node5;
    node5->next = node6;
    traverse(node4);
    cout << "\n";

    ListNode* headAns = addTwoNumbers(node1, node4);
    traverse(headAns);

    return 0;
}
