class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> graph;
        int len = arr.size();
        if (len == 1) return 0;

        for (int i = 0; i < len; ++i) 
            graph[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        int steps = 0;

        while (!q.empty())
        {
            ++steps;
            int levelLength = q.size();

            for (int i = 0; i < levelLength; ++i) {
                int j = q.front();
                q.pop();

                if (j > 0 && graph.find(arr[j-1]) != graph.end()) {
                    q.push(j-1);
                }

                if (j < len-1 && graph.find(arr[j+1]) != graph.end()) {
                    if (j+1 == len-1) 
                        return steps;
                    q.push(j+1);
                }

                if (graph.find(arr[j]) != graph.end()) {
                    for (int k : graph[arr[j]]) {
                        if (k != j) {
                            if (k == len-1) 
                                return steps;
                            q.push(k);
                        }
                    }
                }

                graph.erase(arr[j]);
            }
        }

        return steps;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
