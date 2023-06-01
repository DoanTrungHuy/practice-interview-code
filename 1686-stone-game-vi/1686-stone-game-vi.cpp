class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> sums;
        int n = aliceValues.size();
        
        for (int i = 0; i < n; ++i) {
            int a = aliceValues[i];
            int b = bobValues[i];
            sums.push_back({-(a + b), a, b});
        }
        
        sort(sums.begin(), sums.end());
        
        int alice = 0, bob = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                alice += sums[i][1];
            }
            else {
                bob += sums[i][2];
            }
        }
        
        if (alice > bob) {
            return 1;
        }
        else if (alice < bob) {
            return -1;
        }
        
        return 0;
    }
};