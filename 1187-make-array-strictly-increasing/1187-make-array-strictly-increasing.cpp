int memo[2001][2001];

class Solution {
private:
    vector<int> arr1, arr2;
    int n, m;
    
public:
    int dp(int i, int j, int prev) {
        if (i == n) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int ans = INT_MAX;
        
        if (prev < arr1[i]) {
            ans = min(ans, dp(i + 1, j, arr1[i]));
        }
        
        j = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (j < m) {
            int change = dp(i + 1, j + 1, arr2[j]);
            
            if (change != INT_MAX) {
                ans = min(ans, 1 + change);
            }
        }
        
        return memo[i][j] = ans;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        this->arr1 = arr1;
        this->arr2 = arr2;
        this->n = arr1.size(), this->m = arr2.size();
        memset(memo, -1, sizeof(memo));
        sort(this->arr2.begin(), this->arr2.end());
        
        int ans = dp(0, 0, -1);
        
        return ans == INT_MAX ? -1 : ans;
    }
};