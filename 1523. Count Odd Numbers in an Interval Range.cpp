class Solution {
public:
    int countOdds(int low, int high) {
        int count = ((high+1)/2 - (low+1)/2);
        if (low%2 == 1) ++count;
        return count;
    }
};
