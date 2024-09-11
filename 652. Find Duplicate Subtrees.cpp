class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dup_subTrees;
        calculateHash(root, dup_subTrees);
        return dup_subTrees;
    }

private:
    unordered_map<string, int> treeHash;

    string calculateHash(TreeNode* root, vector<TreeNode*> &dup_subTrees) {
        if (root == nullptr) return "#";

        string leftSubtreeHash = calculateHash(root->left, dup_subTrees);
        string rightSubtreeHash = calculateHash(root->right, dup_subTrees);
        string rootHash = to_string(root->val) + "," + leftSubtreeHash + "," + rightSubtreeHash;

        if (treeHash.count(rootHash) && treeHash[rootHash] == 1) {
            dup_subTrees.push_back(root);
        }

        treeHash[rootHash]++;
        return rootHash;
    }
};
