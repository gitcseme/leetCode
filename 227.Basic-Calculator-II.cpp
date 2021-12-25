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
    int calculate(string s) {
        stack<int> stk;
        int current = 0;
        char op = '+';
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (isdigit(s[i])) {
                current = current * 10 + (s[i] - '0');
            }
            
            if ((!isdigit(s[i]) && s[i] != ' ') || i == len-1) {
                if (op == '+') 
                    stk.push(current);
                else if (op == '-')
                    stk.push(-current);
                else if (op == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * current);
                }
                else if (op == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / current);
                }
                current = 0;
                op = s[i];
            }
        }

        int sum = 0;
        while (!stk.empty()) {
            int n = stk.top();
            stk.pop();
            sum += n;
        }
        
        return sum;
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
    cout << sln.calculate(" 3/2 ") << nline;

    return 0;
}
