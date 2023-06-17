using ll = long long;

ll memo[1001][2001];
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll C(int k, int n) {
        if (n == k or k == 0) {
            return 1;
        }
        if (k == 1) {
            return n;
        }
        if (memo[n][k] != -1) {
            return memo[n][k];
        }
        return memo[n][k] = (C(k - 1, n - 1) + C(k, n - 1)) % MOD;
    }
    
    ll dac(vector<int> nums) {
        if (nums.size() <= 2) {
            return 1;
        }
        vector<int> left, right;
        for (int num : nums) {
            if (num == nums[0]) {
                continue;
            }
            else if (num < nums[0]) {
                left.push_back(num);
            }
            else {
                right.push_back(num);
            }
        }
        int n = left.size(), m = right.size();
        return ((C(m, n + m) * dac(left) % MOD) * dac(right)) % MOD;
    }
    
    int numOfWays(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return (int)dac(nums) - 1;
    }
};