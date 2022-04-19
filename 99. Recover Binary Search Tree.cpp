/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> nodes;
    int l, r;
    
    void recoverTree(TreeNode* root) {
        inorder(root);
    
        int len = nodes.size();
        for (int i = len-1; i > 0; --i) {
            if (nodes[i] < nodes[i-1]) {
                r = nodes[i];
                break;
            }
        }
        
        for(int i = 0; i < len; ++i) {
            if (nodes[i] > r) {
                l = nodes[i];
                break;
            }
        }
        
        traverseTree(root);
    }
    
    void traverseTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        if (root->val == l) {
            root->val = r;
        }
        else if (root->val == r) {
            root->val = l;
        }
        
        traverseTree(root->left);
        traverseTree(root->right);
    }
    
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
};
