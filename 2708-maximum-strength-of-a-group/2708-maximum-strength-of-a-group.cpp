using ll = long long;

class Solution {
private:
    vector<int> nums;
    int n;
    ll res;
    
public:
    void dfs(int i, ll s, int c) {
        if (i == n) {
            if (c == 0) {
                return;
            }
            res = max(res, s);
            return;
        }
        for (int j = 0; j < 2; ++j) {
            dfs(i + 1, s * ((j == 1) ? nums[i] : 1), c + (j == 1));
        }
    }
    long long maxStrength(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        res = INT_MIN;
        dfs(0, 1, 0);
        return res;
    }
};