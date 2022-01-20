class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int len = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = (left + right) / 2;

            int hourSpent = 0;
            for (int i = 0 ; i < len; ++i) {
                hourSpent += ceil(1.0*piles[i]/mid);
                if (hourSpent > h) break;
            }
            
            if (hourSpent <= h) 
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
