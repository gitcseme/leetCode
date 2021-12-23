#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define nline "\n"
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define debug(args...){string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename... Args> void err(istream_iterator<string> it,T a,Args... args){cerr<<*it<<" = "<<a<<"\n";err(++it,args...);}
template<typename T> void _print(T _t){cout<<"[ ";for(auto _x:_t){cout<<_x<<" ";}cout<<"]\n";}
template<class T> void _print(map<T, T> x){for(auto i:x)cout<<i.ff<<" "<<i.ss<<"\n";}
/*---------------------------Codes-----------------------------*/

class Solution {
    int indegree[2005];
    vector<int> adjacent[2005];
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> edge : prerequisites) {
            adjacent[edge[1]].push_back(edge[0]);
            ++indegree[edge[0]];
        }

        vector<int> zeroIndegreeNodes;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                zeroIndegreeNodes.push_back(i);
                result.push_back(i);
            }
        }

        for (int i : zeroIndegreeNodes) {
            dfs(i);
        }

        if (result.size() == numCourses) 
            return result;
        
        return {};
    }

    void dfs(int u) {
        for (int v : adjacent[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                result.push_back(v);
                dfs(v);
            }
        }
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    FASTIO;
#ifdef DEBUG_LOCAL
    FI;
#endif
    
    // vector<vector<int>> cources = { {1,0},{2,0},{3,1},{3,2} };
    vector<vector<int>> cources = {  };

    Solution sln;
    vector<int> ans = sln.findOrder(1, cources);

    _print(ans);

    return 0;
}
