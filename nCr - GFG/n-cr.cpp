//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int PowMod(long long int x,long long int n,long long int M)
	{
	    if (n == 0) {
	        return 1;
	    }
	    long long int res = PowMod(x, n / 2, M);
	    res = (res * res) % M;
	    if (n & 1) {
	        return (res * x) % M;
	    }
	    return res;
	}
	
    int nCr(int n, int r){
        if (r > n) {
            return 0;
        }
        using ll = long long;
        const ll MOD = 1e9 + 7;
        ll p[n + 1];
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = (p[i - 1] * i) % MOD;
        }
        ll res = p[n];
        res = (res * PowMod(p[n - r], MOD - 2, MOD)) % MOD;
        res = (res * PowMod(p[r], MOD - 2, MOD)) % MOD;
        return res;
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