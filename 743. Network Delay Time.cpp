struct Node {
    int value;
    Node() {}
    Node(int val) { 
        value = val;
    }
};

vector<int> d;

bool operator < (Node a, Node b) {
    return d[a.value] > d[b.value];
}

class Solution {
public:
    vector<Node> g;
    vector<vector<int>> adj;
    vector<bool> vis;
    map<pair<int, int>, int> cost;
    int INF = 9999999;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.resize(n+1);
        adj.resize(n+1);
        d.resize(n+1);
        vis.resize(n+1);
        for(int i = 1; i <= n; ++i) {
            g[i] = Node(i);
            d[i] = INF;  
            vis[i] = false;
        }
        
        for (auto t : times) {
            adj[t[0]].push_back(t[1]);
            cost[{t[0], t[1]}] = t[2];
        }
        
        dijkstra(k);
        
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) return -1;
            maxTime = max(maxTime, d[i]);
        }
        
        return maxTime;
    }
    
    void dijkstra(int src) {
        priority_queue <Node> pq;
        d[src] = 0;
        pq.push(g[src]);
        
        while (!pq.empty()) {
            int u = pq.top().value;
            pq.pop();
            vis[u] = true;
            
            for (int v : adj[u]) {
                if (d[u] + cost[{u, v}] < d[v]) {
                    d[v] = d[u] + cost[{u, v}];
                    pq.push(g[v]);
                }
            }
        }
    }

};
