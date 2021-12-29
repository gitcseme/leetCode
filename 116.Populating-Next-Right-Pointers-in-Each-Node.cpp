
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root != NULL)
            bfs(root);
        return root;
    }

    void bfs(Node* root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelLength = q.size();

            Node *prev, *left, *right;
            for (int i = 0; i < levelLength; ++i) {
                Node* curr = q.front();
                q.pop();
                if (curr->left != NULL) {
                    left = curr->left;
                    right = curr->right;
                    q.push(left);
                    q.push(right);

                    left->next = right;
                    if (i != 0)
                        prev->next = left;

                    prev = right;
                }                
            }
        }
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
