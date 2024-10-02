class Solution {
public:
    int kthElem = -1;

    void dfs(TreeNode* root, int& k) {
        if (root == nullptr) return;

        dfs(root->left,  k);
        
        --k;
        if (k == 0) kthElem = root->val;
        
        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return kthElem;
    }
};
