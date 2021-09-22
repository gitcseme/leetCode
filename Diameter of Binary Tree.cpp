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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dp(root, result);
        return result - 1;
    }

    int dp(TreeNode* root, int &result) {
        if (root == NULL)
            return 0;

        int L = dp(root->left, result);
        int R = dp(root->right, result);

        int subtreeMaxHeight = max(L, R) + 1;
        int subtreeDiameter = 1 + L + R;
        result = max(subtreeDiameter, result);

        return subtreeMaxHeight;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sln;
    int diameter = sln.diameterOfBinaryTree(root);
    cout << diameter << "\n";

    return 0;
}

