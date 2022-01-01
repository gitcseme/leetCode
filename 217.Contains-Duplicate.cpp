class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, len = nums.size(); i < len-1; ++i) 
            if (nums.at(i) == nums.at(i+1)) 
                return true;
                
        return false;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
