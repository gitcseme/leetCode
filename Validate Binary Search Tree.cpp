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
    bool isValidBST(TreeNode* root) {
        return traverseTree(root, INT_MIN * 1ll - 99, INT_MAX * 1ll + 99);
    }

    bool traverseTree(TreeNode* node, long long LEFT, long long RIGHT) {
        if (node == nullptr)
            return true;

        if (node->val <= LEFT || node->val >= RIGHT)
            return false;

        bool leftBST = traverseTree(node->left, LEFT, node->val);
        bool rightBST = traverseTree(node->right, node->val, RIGHT);
        return (leftBST && rightBST);
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sln;
    cout << sln.isValidBST(root) << "\n";

    return 0;
}

