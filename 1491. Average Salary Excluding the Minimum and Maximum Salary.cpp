class Solution {
public:
    double average(vector<int>& salary) {
        /*sort(salary.begin(), salary.end());
        double total = 0.0;
        int len = salary.size();
        for (int i = 1; i < len-1; ++i) {
            total += salary[i];
        }
        
        return (total / (len-2));*/
        
        double mx = 0, mn = 1000000000, total = 0;
        int len = salary.size();
        for (int i = 0; i < len; ++i) {
            total += salary[i];
            
            if (mn > salary[i]) mn = salary[i];
            if (mx < salary[i]) mx = salary[i];
        }
        
        return (total - mn - mx) / (len-2);
    }
};
