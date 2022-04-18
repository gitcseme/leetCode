class Solution {
public:
    vector<int> nodes;
    int kthSmallest(TreeNode* root, int k) {
        preOrder(root, k);
        return nodes[k-1];
    }
    
    void preOrder(TreeNode* root, int k) {
        if (root == nullptr) 
            return;
        
        preOrder(root->left, k-1);
        nodes.push_back(root->val);
        preOrder(root->right, k-1);
    }
};
