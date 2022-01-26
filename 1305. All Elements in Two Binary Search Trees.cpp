
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> values;
        inorderTraverse(root1, values);
        inorderTraverse(root2, values);
        
        sort(values.begin(), values.end());
        return values;
    }
    
    void inorderTraverse(TreeNode *node, vector<int> &values) {
        if (node == nullptr) {
            return;
        }
        
        inorderTraverse(node->left, values);
        values.push_back(node->val);
        inorderTraverse(node->right, values);
    }
};
