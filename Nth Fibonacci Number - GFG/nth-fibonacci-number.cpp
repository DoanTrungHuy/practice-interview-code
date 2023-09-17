//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


const int MOD = 1e9 + 7;

class Solution {
private:
    vector<int> memo;
    
public:
    int dp(int n) {
        if (n <= 1) {
            return n;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        return memo[n] = (dp(n - 1) + dp(n - 2)) % MOD;
    }
    int nthFibonacci(int n){
        memo.resize(n + 1, -1);
        return dp(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends