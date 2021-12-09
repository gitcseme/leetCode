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
template<typename T> void _print(T _t){cout<<"[ ";for(auto _x:_t){cout<<_x<<" ";}cout<<" ]\n";}
template<class T> void _print(map<T, T> x){for(auto i:x)cout<<i.ff<<" "<<i.ss<<"\n";}
/*---------------------------Codes-----------------------------*/

class Solution {
    int mem[5*10000 + 5];
    bool vis[5*10000 + 5];
    int len;
public:
    bool canReach(vector<int>& arr, int start) {
        memset(mem, -1, sizeof(mem));
        memset(vis, false, sizeof(vis));
        len = arr.size();
        return solve(arr, start) >= 1;
    }

    int solve(vector<int>& a, int i) {

        if (i < 0 || i >= len) return 0;
        int elem = a[i];
        if (elem == 0) return 1;

        if (mem[i] != -1) return mem[i];
        vis[i] = true;

        int way1 = 0;
        if (i + elem < len && !vis[i + elem])
            way1 = solve(a, i + elem);
        
        int way2 = 0; 
        if (i - elem >= 0 && !vis[i - elem])
            way2 = way2 = solve(a, i - elem);

        return mem[i] = way1 + way2;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    FASTIO;
#ifdef DEBUG_LOCAL
    FI;
#endif
    
    Solution sln;
    vector<int> a = {4,2,3,0,3,1,2};
    int start = 0;
    bool ans = sln.canReach(a, start);

    cout << ans << nline;

    return 0;
}
