#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1 != NULL) current->next = l1;
        if (l2 != NULL) current->next = l2;
        return dummy->next;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

void traverse(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

int main() {
    //FI;

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;

    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(3);
    ListNode* n6 = new ListNode(4);
    ListNode* n7 = new ListNode(5);
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    Solution sln;
    traverse(sln.mergeTwoLists(n1, n4));


    return 0;
}



















