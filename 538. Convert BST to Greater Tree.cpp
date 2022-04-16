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
    unordered_map<int, int> m;
    
    TreeNode* convertBST(TreeNode* root) {
        vector<int> nodes;
        traverse(root, nodes);
        sort(nodes.begin(), nodes.end());
        
        //unordered_map<int, int> m;
        int len = nodes.size();
        int sum = 0;
        for (int i = len-1; i >= 0; --i) {
            m[nodes[i]] = sum + nodes[i];
            sum += nodes[i];
        }
        
        solve(root);
        
        return root;
    }
    
    void solve(TreeNode* root) {
        if (root == nullptr) return;
        root->val = m[root->val];
        solve(root->left);        
        solve(root->right);
    }
    
    void traverse(TreeNode* root, vector<int> &nodes) {
        if (root == nullptr)
            return;
        
        nodes.push_back(root->val);
        
        traverse(root->left, nodes);        
        traverse(root->right, nodes);

    }
};
