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

void inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size()-1);
    }

    TreeNode* build_tree(vector<int> nums, int left, int right) {
        if (left > right)
            return NULL;

        int midIndex = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[midIndex]);
        node->left = build_tree(nums, left, midIndex-1);
        node->right = build_tree(nums, midIndex+1, right);
        return node;
    }
};
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    vector<int> nums = { -10, -3, 0, 5, 9 };
    Solution sln;
    TreeNode* root = sln.sortedArrayToBST(nums);
    inorderTraversal(root);

    return 0;
}

