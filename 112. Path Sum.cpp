class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) 
            return false;
        
        return solve(root, 0, targetSum);
        
    }
    
    bool solve(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) 
            return false;
            
        if (root != nullptr && root->left == nullptr && root->right == nullptr) {
            return ((sum + root->val) == targetSum) ? true : false;
        }
        
        bool left = solve(root->left, sum + root->val, targetSum);
        bool right = solve(root->right, sum + root->val, targetSum);
        
        return left || right;
    }
};
