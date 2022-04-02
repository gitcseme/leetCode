class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
    
    static bool comp(int a, int b) {
        int aones = __builtin_popcount(a);
        int bones = __builtin_popcount(b);
        
        return aones != bones ? aones < bones : a < b;
    }
};
