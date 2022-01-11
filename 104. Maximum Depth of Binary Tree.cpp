class Solution {
public:
    int maxDepth(TreeNode* root) {
        int mxLevel = 0;
        getMaxDepth(root, 0, mxLevel);
        return mxLevel;
    }
    
    void getMaxDepth(TreeNode* root, int level, int &mxLevel) {
        if (root == nullptr) {
            mxLevel = max(mxLevel, level);
            return;
        }
        
        getMaxDepth(root->left, level+1, mxLevel);        
        getMaxDepth(root->right, level+1, mxLevel);
    }
};
