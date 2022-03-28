class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0, len = nums.size();
        
        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                nums[k] = nums[i];
                ++k;
            }
        }
        
        while (k < len) nums[k++] = 0;
    }
};
