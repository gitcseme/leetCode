class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        v.push_back(nums[0]);
        for (int i = 1, len = nums.size(); i < len; ++i) {
            v.push_back(v[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return v[right];
        
        return v[right] - v[left - 1];
    }
};
