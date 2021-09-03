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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> levels[2005];
        vector<vector<int>> bottomUplevels;
        if (root == NULL) return bottomUplevels;

        traverseTree(root, 0, levels);
        for(int i = 2000; i >= 0; --i) {
            vector<int> local;
            if (levels[i].size() > 0) {
                for(int x : levels[i])
                    local.push_back(x);

                bottomUplevels.push_back(local);
            }
        }
        return bottomUplevels;
    }

    void traverseTree(TreeNode* root, int level, vector<int> levels[]) {
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

    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(9);
    root->left = node1;

    TreeNode* node2 = new TreeNode(20);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(7);
    node2->left = node3;
    node2->right = node4;
    root->right = node2;

    Solution sln;
    vector<vector<int>> r = sln.levelOrderBottom(root);
    for (vector<int> v : r) {
        FOR(v);
    }

    return 0;
}

