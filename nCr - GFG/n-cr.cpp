//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if (r > n) {
            return 0;
        }
        using ll = long long;
        ll dp[n + 1][r + 1];
        memset(dp, 0, sizeof(dp));
        const ll MOD = 1e9 + 7;
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= r; ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                }
                else if (i == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
            }
        }
        
        return (int)dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends