class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        long long total = 0;
        dfs(root, "", total);
        return total;
    }
    
    void dfs(TreeNode *root, string bin, long long& total) {
        if (root == nullptr) return; // internal node's left or right NULL chield [we should ignore]
        
        if (root->left == nullptr && root->right == nullptr) { // Got a leaf node
            bin += (root->val == 1 ? '1' : '0');
            total += calculate(bin);
            return;
        }
        
        bin = bin + (root->val == 1 ? '1' : '0');
        dfs(root->left, bin, total);        
        dfs(root->right, bin, total);
    }
    
    int calculate(string bin) {
        int num = 0, p = 1;
        for (int i = bin.length()-1; i >= 0; --i) {
            if (bin[i] == '1') num += p;
            p = 2 * p;
        }
        return num;
    }
};
