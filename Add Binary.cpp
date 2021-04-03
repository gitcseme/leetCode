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
    string addBinary(string a, string b) {
        char c = '0';
        string addition;
        int i = a.length()-1, j = b.length()-1;
        while (i >= 0 || j >= 0) {
            char x = i >= 0 ? a[i] : '0';
            char y = j >= 0 ? b[j] : '0';

            if (x == '0' && y == '0') {
                addition += c;
                c = '0';
            }
            else if (x == '1' && y == '1') {
                if (c == '1') addition += '1';
                else addition += '0';
                c = '1';
            }
            else {
                if (c == '1') addition += '0';
                else addition += '1';
            }
            --i, --j;
        }
        if (c == '1') addition += '1';

        reverse(addition.begin(), addition.end());
        return addition;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    string a = "100", b = "110010";
    cout << sln.addBinary(a, b) << "\n";

    return 0;
}

