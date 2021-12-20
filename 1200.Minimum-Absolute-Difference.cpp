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
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        //unordered_map<int, vector< vector<int> > > pairs;
        vector<vector<int>> min_pairs;

        int min_diff = INT_MAX;
        for (int i = 1, len = arr.size(); i < len; ++i) {
            int diff = arr[i] - arr[i-1];
            if (diff < min_diff) {
                min_diff = diff;
                min_pairs.clear();
                min_pairs.push_back({arr[i-1], arr[i]});
            }
            else if (diff == min_diff) {
                min_pairs.push_back({arr[i-1], arr[i]});
            }
        }

        return min_pairs;
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
    vector<int> a = {3,8,-10,23,19,-4,-14,27};
    vector<vector<int>> ans = sln.minimumAbsDifference(a);
    for (vector<int> v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}
