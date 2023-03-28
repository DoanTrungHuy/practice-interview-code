class Solution {
public:
    long long countVowels(string word) {
        const int n = word.size();
        long long dp[n];
        long long ans = 0;
        string vowels = {'a', 'e', 'i', 'o', 'u'};
        dp[0] = 0;
        
        if (vowels.find(word[0]) != string::npos) {
            dp[0] = 1;
            ans += 1;
        }
        
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            if (vowels.find(word[i]) != string::npos) {
                dp[i] += (i + 1);
            }
            ans += dp[i];
        }
        
        return ans;
    }
};