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
    string decodeString(string s) {
        vector<string> chunks = processInput(s);

        while (true)
        {
            int r = findNext_rsb(chunks);
            int l = findNearest_lsb(chunks, r);
            if (l == -1 || r == -1) break;
            
            int mul = 0;
            if (l > 0 && isdigit(chunks[l-1][0])) {
                stringstream sso(chunks[l-1]);
                sso >> mul;
            }

            string t = getEnclosedValues(chunks, l, r);
            string x = t;
            for (int i = 2; i <= mul; ++i) x += t;
            
            fitString(chunks, l, r, x);
            _print(chunks);
        }
        
        string result = "";
        for (string s : chunks) result += s;

        return result;
    }

    string getEnclosedValues(vector<string>& chunks, int l, int r) {
        string s = "";
        for (int i = l+1; i < r; ++i) s += chunks[i];
        return s;
    }

    void fitString(vector<string>& chunks, int l, int r, string x) {
        for (int i = r; i >= l; --i) 
            chunks.erase(chunks.begin() + i);
        chunks[l-1] = x;
    }

    int findNext_rsb(vector<string>& chunks) {
        for (int i = 0; i < chunks.size(); ++i)
            if (chunks[i] == "]") return i;
        
        return -1;
    }

    int findNearest_lsb(vector<string>& chunks, int r) {
        for (int i = r-1; i >= 0; --i) 
            if (chunks[i] == "[")
                return i;

        return -1;
    }

    vector<string> processInput(string s) {
        vector<string> tokens;
        for (int i = 0, len = s.size(); i < len; ) {
            string e = "";
            if (isdigit(s[i])) while (isdigit(s[i])) e += s[i++];
            else if (isalpha(s[i])) while (isalpha(s[i])) e += s[i++];
            else if (s[i] == '[' || s[i] == ']') e += s[i++];
            tokens.push_back(e);
        }

        return tokens;
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
    string s = "abc3[cd]xyz";
    cout << sln.decodeString(s);

    return 0;
}
