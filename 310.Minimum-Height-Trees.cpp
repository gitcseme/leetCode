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
    map<pair<int, int>, int> map;
    unordered_map<int, vector<int>> mhts;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (vector<int> v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }

        int minHeight = n;
        for (int i = 0; i < n; ++i) {
            int h = traverse(i, i, g);
            minHeight = min(minHeight, h);
            mhts[h].push_back(i);
        }

        return mhts[minHeight];
    }

    int traverse(int i, int prev, vector<vector<int>>& g) {
        
        int height = 0, mxHeight = 0;
        for (int j : g[i]) {
            if (j != prev) {
                //int store = map.find({i, j}) != map.end() ? map[{i, j}] : -1;
                if (map.find({i, j}) != map.end()) {
                    height = map[{i, j}];
                }
                else {
                    height = 1 + traverse(j, i, g);
                }
                map[{i, j}] = height;
                mxHeight = max(mxHeight, height);
            }
        }

        return mxHeight;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    FASTIO;
#ifdef DEBUG_LOCAL
    FI;
#endif
    
    vector<vector<int>> edges = { {0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6} };
    Solution sln;
    vector<int> ans = sln.findMinHeightTrees(7, edges);
    _print(ans);

    return 0;
}
