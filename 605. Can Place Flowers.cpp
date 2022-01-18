class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if (len == 1) {
            if (flowerbed[0] == 0)
                --n;
        }
        else if (len == 2) {
            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                --n;
            }
        }
        else {
            for (int i = 0; i < len; ++i) {
                if (flowerbed[i] == 0) {
                    if (i == 0) {
                        if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                            flowerbed[i] = 1;
                            --n;
                        }
                    }
                    else if (i == len-1) {
                        if (flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                            flowerbed[i] = 1;
                            --n;
                        }
                    }
                    else if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        --n;
                    }
                }
            }    
        }
        
        
        return n <= 0;
    }
};
