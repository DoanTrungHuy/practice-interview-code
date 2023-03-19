class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int sum = 0;
        int n = flips.size();
        int calc = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += (i + 1);
            calc += flips[i];
            ans += sum == calc;
        }
        
        return ans;
    }
};