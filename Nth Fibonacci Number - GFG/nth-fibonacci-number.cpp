//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        int f[n + 1];
        f[0] = 0;
        f[1] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 0; i <= n - 2; ++i) {
            f[i + 2] = (f[i + 1] + f[i]) % MOD;
        }
        return f[n];
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