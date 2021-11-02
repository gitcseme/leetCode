#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacent(numCourses);

        for(int i = 0; i < prerequisites.size(); ++i) {
            indegree[prerequisites[i][0]]++;
            adjacent[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> currentFree;
        for (int i = 0; i < numCourses; ++i)
            if (!indegree[i]) currentFree.push(i);

        int takenCourses = 0;
        BFS(currentFree, takenCourses, indegree, adjacent);

        return takenCourses == numCourses;
    }

    void BFS(queue<int> q, int& takenCourses, vector<int> indegree, vector<vector<int>> adjacent)
    {
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            ++takenCourses;

            for (int next : adjacent[current]) {
                --indegree[next];
                if (!indegree[next])
                    q.push(next);
            }
        }
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    Solution sln;
    vector<vector<int>> courseDependencies = {{1, 0}, {0, 1}};
    cout << sln.canFinish(2, courseDependencies) << "\n";

    return 0;
}

