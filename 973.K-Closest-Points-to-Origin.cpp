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
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> nearest;
        for (vector<int> point : points) {
            int d = point[0]*point[0] + point[1]*point[1];
            nearest.push_back({d, point });
        }

        sort(nearest.begin(), nearest.end(), less<pair<int, vector<int>>>());
        
        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back({nearest[i].second});
        }

        return ans;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    FASTIO;
#ifdef DEBUG_LOCAL
    FI;
#endif
    
    vector<vector<int>> points = { {3,3},{5,-1},{-2,4} };
    Solution sln;
    auto ans = sln.kClosest(points, 2);

    for (auto p : ans) {
        cout << p[0] << " " << p[1] << nline;
    }

    return 0;
}
