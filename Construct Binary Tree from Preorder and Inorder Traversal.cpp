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
    int preorderRootIndex = 0;
    map<int, int> inorderIndexMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;

        return buildTreeFromTraversal(preorder, 0, preorder.size()-1);
    }

    TreeNode* buildTreeFromTraversal(vector<int>& preorder, int left, int right) {
        if (left > right)
            return NULL;

        int rootValue = preorder[preorderRootIndex++];
        TreeNode* root = new TreeNode(rootValue);

        root->left = buildTreeFromTraversal(preorder, left, inorderIndexMap[rootValue]-1);
        root->right = buildTreeFromTraversal(preorder, inorderIndexMap[rootValue]+1, right);
        return root;
    }

    // CHECK INORDER
    void traverseTree(TreeNode* node) {
        if (node == NULL)
            return;

        traverseTree(node->left);
        cout << node->val << ", ";
        traverseTree(node->right);
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    Solution sln;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = sln.buildTree(preorder, inorder);
    sln.traverseTree(root);

    return 0;
}

