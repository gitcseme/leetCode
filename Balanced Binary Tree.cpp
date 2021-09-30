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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        traverseTree(root, result);
        return result;
    }

    int traverseTree(TreeNode* node, bool &result) {
        if (node == nullptr)
            return 0;

        int l_height = traverseTree(node->left, result);
        int r_height = traverseTree(node->right, result);
        if (abs(l_height - r_height) > 1)
            result = false;

        return 1 + max(l_height, r_height);
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);

    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    Solution sln;
    cout << sln.isBalanced(root) << "\n";

    return 0;
}

