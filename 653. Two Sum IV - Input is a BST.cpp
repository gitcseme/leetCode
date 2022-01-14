
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        traverse(root, nodes);
        
        int i = 0, j = nodes.size()-1;
        
        while (i < j) {
            int sum = nodes[i] + nodes[j];
            if (sum == k) {
                return true;
            }
            else if (sum < k) ++i;
            else --j;
        }
            
        return false;
    }
    
    void traverse(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr)
            return;
        
        traverse(root->left, nodes);        
        nodes.push_back(root->val);
        traverse(root->right, nodes);
    }
};
