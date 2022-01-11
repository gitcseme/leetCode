class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        bfs(root, levels);
        return levels;
    }
    
    void bfs(TreeNode *root, vector<vector<int>>& levels) {
        if (root == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> level;
            
            for (int i = 0; i < level_size; ++i) {
                TreeNode* current = q.front();
                level.push_back(current->val);
                q.pop();
                
                if (current->left != nullptr)
                    q.push(current->left);                
                
                if (current->right != nullptr)
                    q.push(current->right);
            }
            levels.push_back(level);
        }
    }
};
