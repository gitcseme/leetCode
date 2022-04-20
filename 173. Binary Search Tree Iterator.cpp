class BSTIterator {
public:
    vector<int> nodes;
    int L, i = 0;
    BSTIterator(TreeNode* root) {
        inorder(root);
        L = nodes.size();
    }
    
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        return nodes[i++];
    }
    
    bool hasNext() {
        return i < L;
    }
};

