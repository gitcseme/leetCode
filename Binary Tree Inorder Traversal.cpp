#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
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
    vector<int> traverseOrder;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        if (root->left != NULL) inorderTraversal(root->left);
        traverseOrder.push_back(root->val);
        if (root->right != NULL) inorderTraversal(root->right);

        return traverseOrder;
    }

};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    TreeNode *root = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    root->left = n2;
    root->right = n3;
    n3->left = n4;
    n3->right = n5;

    Solution sln;
    auto inTrav = sln.inorderTraversal(root);
    for (int n : inTrav)
        cout << n << " ";

    return 0;
}

