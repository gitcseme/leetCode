class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> f(1001, 0);
        for (int i = 0, len = nums1.size(); i < len; ++i) {
            ++f[nums1[i]];
        }
        
        vector<int> ins;
        for (int i = 0, len = nums2.size(); i < len; ++i) {
            if (f[nums2[i]] > 0) {
                ins.push_back(nums2[i]);
                --f[nums2[i]];
            }
        }
        
        return ins;
    }
};
