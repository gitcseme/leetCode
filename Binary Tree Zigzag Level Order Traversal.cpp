#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> levels[2500];
        if (root == NULL) return ans;

        traverseTree(root, 0, levels);
        for(int i = 0; i < 2500; ++i) {
            vector<int> local;
            for(int x : levels[i])
                local.push_back(x);

            if (local.size() != 0)
                ans.push_back(local);
        }

        return ans;
    }

    void traverseTree(TreeNode* root, int level, vector<int>levels[]) {

        if (level%2 == 1)
            levels[level].insert(levels[level].begin(), root->val);
        else
            levels[level].push_back(root->val);

        if (root->left != NULL)
            traverseTree(root->left, level+1, levels);
        if (root->right != NULL)
            traverseTree(root->right, level+1, levels);
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;


    return 0;
}

