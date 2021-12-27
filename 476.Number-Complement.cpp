class Solution {
public:
    int findComplement(int num) {
        string bin = bitset<31>(num).to_string();
        for (int i = 0; i < 31; ++i) {
            if (bin[i] == '1') {
                bin = bin.substr(i);
                break;
            }
        }

        for (int i = 0; i < bin.size(); ++i) 
            bin[i] = (bin[i] == '1') ? '0' : '1';

        int decimal = 0, len = bin.size()-1;
        for (int i = len; i>= 0; --i) 
            if(bin[i] != '0')
                decimal += pow(2, len-i);

        return decimal;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
