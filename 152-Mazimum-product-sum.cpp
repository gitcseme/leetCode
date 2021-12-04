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
    int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int curMax = 1, curMin = 1;
		int res = *max_element(nums.begin(), nums.end());

		for (int i = 0; i < n; ++i) {
			int tmpMax = curMax * nums[i];
			curMax = max(max(tmpMax, curMin * nums[i]), nums[i]);
			curMin = min(min(tmpMax, curMin * nums[i]), nums[i]);

			res = max(res, curMax);
		}
		return res;
    }
};

int main() {
    FASTIO;
#ifdef DEBUG_LOCAL
    FI;
#endif
    
	int n;
	cin >> n;
    vector<int> nums(n);
	for (int i = 0; i < n; i++) 
		cin >> nums[i];

	Solution sln;
	cout << sln.maxProduct(nums) << nline;
    

    return 0;
}
