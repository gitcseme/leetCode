#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy->next;

        int length = 0;
        while (current != NULL) {
            ++length;
            current = current->next;
        }

        current = dummy;
        for (int i = 1; i <= length-n; ++i)
            current = current->next;

        current->next = current->next->next;
        return dummy->next;
    }
};

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
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sln;
    ListNode* current = sln.removeNthFromEnd(n1, 1);
    traverse(current);

    return 0;
}


















