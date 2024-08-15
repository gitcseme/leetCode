/*
// Definition for a Node.
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
*/

// Best solution
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int levelLength = Q.size();
            
            for (int i = 0; i < levelLength; ++i) {
                auto u = Q.front();
                Q.pop();

                if (i+1 < levelLength) u -> next = Q.front();
                
                if (u -> left != nullptr)  Q.push(u -> left);
                if (u -> right != nullptr)  Q.push(u -> right);
            }
        }

        return root;
    }
};

// Custom thought
class Solution {
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }

    void bfs(Node * root) {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelLength = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < levelLength; ++i) {
                auto u = q.front();
                q.pop();
                
                if (u -> left == nullptr && u -> right == nullptr) { // leaf node
                    if (prev != nullptr) {
                        prev -> next = u;
                    }
                    prev = u;
                    continue;
                }

                q.push(u -> left);
                q.push(u -> right);
                u -> left -> next = u -> right;
                
                if (prev != nullptr) {
                    prev -> next = u -> left;
                }

                prev = u -> right;
            }
        }
    }
};
