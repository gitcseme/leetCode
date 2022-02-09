class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        set<int> track;
        for (int i = 0, len = nums.size(); i < len-1; ++i) {
            int x = nums[i] + k;
            if (!track.count(nums[i])) {
                if (binary_search(nums.begin()+i+1, nums.end(), x)) {
                    //cout << nums[i] << " " << x << "\n";
                    ++count;
                }
                track.insert(nums[i]);
            }
        }
        
        return count;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
