class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        if (len < 3) { 
            return false;
        }
        
        int i = 0, j = len-1;
        while (i < len-1 && (arr[i] < arr[i+1])) ++i;
        while (j > 0 && arr[j-1] > arr[j]) --j;
        
        return (i > 0 && j < len-1 && i == j);
    }
};
