#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;

        return root1->val == root2->val
            && isMirror(root1->left, root2->right)
            && isMirror(root1->right, root2->left);
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    TreeNode* root = new TreeNode(1);
    TreeNode* l1 = new TreeNode(2);
    TreeNode* l2 = new TreeNode(3);
    TreeNode* l3 = new TreeNode(4);
    root->left = l1;
    //l1->left = l2;
    l1->right = l2;

    TreeNode* r1 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(4);
    TreeNode* r3 = new TreeNode(3);
    root->right = r1;
    r1->left = r3;
    //r1->right = r3;

    Solution sln;
    cout << sln.isSymmetric(root) << "\n";

    return 0;
}






