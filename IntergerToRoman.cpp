#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman;
        roman[1] = "I";
        roman[5] = "V";
        roman[10] = "X";
        roman[50] = "L";
        roman[100] = "C";
        roman[500] = "D";
        roman[1000] = "M";
        roman[4] = "IV";
        roman[9] = "IX";
        roman[] = "XL";
    }
};

int main() {
    //FI;

    return 0;
}
