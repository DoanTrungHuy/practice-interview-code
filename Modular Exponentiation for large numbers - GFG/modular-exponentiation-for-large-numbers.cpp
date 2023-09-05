//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int MOD)
		{
		    if (n == 0) {
		        return 1;
		    }
		    long long int res = PowMod(x, n / 2, MOD);
		    res = (res * res) % MOD;
		    if (n & 1) {
		        return (res * x) % MOD;
		    }
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends