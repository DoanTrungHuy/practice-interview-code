class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        
        vector<vector<int>> dp2(n,vector<int>(26, 0));
        
        vector<int> dp(26, 0);
        
        for(int i = 0; i < n; i++){
            int curr = s[i] - 'a';
           
            int val = 0;
            for(int j = 0; j < 26; j++){
                if(abs(curr - j) <= k){
                    val = max(val, dp[j] + 1);
                }
            }
            
            dp[curr] = max(val, 1);
        }
        
        return *max_element(dp.begin(), dp.end());
        
    }
};