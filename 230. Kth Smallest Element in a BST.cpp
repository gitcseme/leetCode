class Solution {
public:
    int elem = -1;
    bool found = false;

    void dfs(TreeNode* root, int& k) {
        if (root == nullptr || found) return;

        dfs(root->left,  k);
        
        --k;
        if (!found && k == 0) {
            elem = root->val;
            found = true;
            return;
        }

        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return elem;
    }
};
