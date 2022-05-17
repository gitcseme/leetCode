class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* oroot, TreeNode* croot, TreeNode* target) {
        if (oroot == nullptr) return nullptr;
        if (oroot->val == target->val) return croot;
        
        TreeNode *L = getTargetCopy(oroot->left, croot->left, target);
        TreeNode *R = getTargetCopy(oroot->right, croot->right, target);
        
        return L == nullptr ? R : L;
    }
};
