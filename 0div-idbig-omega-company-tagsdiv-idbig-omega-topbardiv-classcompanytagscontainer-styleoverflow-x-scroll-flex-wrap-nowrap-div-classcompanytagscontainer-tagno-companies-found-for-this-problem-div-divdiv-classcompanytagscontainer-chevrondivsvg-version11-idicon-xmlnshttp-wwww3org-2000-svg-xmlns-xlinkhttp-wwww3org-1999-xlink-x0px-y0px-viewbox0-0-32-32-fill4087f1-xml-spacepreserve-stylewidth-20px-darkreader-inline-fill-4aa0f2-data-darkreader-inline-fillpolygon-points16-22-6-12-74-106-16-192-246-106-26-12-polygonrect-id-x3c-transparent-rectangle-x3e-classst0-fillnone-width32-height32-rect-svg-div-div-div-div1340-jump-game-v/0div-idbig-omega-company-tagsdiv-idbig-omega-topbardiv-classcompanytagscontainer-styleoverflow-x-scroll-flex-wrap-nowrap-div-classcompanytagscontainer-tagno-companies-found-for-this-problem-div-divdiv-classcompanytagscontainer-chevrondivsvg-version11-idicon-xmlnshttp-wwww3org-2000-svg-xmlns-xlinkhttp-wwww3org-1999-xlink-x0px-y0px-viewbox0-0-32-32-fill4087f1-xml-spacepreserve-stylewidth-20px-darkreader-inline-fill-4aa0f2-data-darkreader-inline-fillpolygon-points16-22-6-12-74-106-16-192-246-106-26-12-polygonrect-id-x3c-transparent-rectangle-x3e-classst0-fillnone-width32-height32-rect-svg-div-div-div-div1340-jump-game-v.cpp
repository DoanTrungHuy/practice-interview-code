int memo[1001];

class Solution {
private:
    vector<int> arr;
    int d;
    
public:
    int dp(int i) {
        if (memo[i] != -1) {
            return memo[i];
        }    
        const int n = arr.size();
        int ans = 0;
        for (int j = 1; j <= d; ++j) {
            if (i + j < n) {
                if (!(arr[i] > arr[i + j])) {
                    break;
                }
                ans = max(ans, 1 + dp(i + j));
            }
            else {
                break;
            }
        }
        for (int j = 1; j <= d; ++j) {
            if (i - j >= 0) {
                if (!(arr[i] > arr[i - j])) {
                    break;
                }
                ans = max(ans, 1 + dp(i - j));
            }
            else {
                break;
            }
        }
        return memo[i] = ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        this->d = d;
        this->arr = arr;
        memset(memo, -1, sizeof(memo));
        const int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, 1 + dp(i));
        }
        return ans;
    }
};