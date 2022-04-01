class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
    
    void traverse(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
};
