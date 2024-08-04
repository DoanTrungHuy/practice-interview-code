class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        using pii = pair<int, int>;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i + 1});
        }
        
        const int MOD = 1e9 + 7;
        int ans = 0;
        
        for (int curr = 1; curr <= right; ++curr) {
            auto [val, next_idx] = pq.top();
            pq.pop();
            
            if (curr >= left) {
                ans = (ans + val) % MOD;
            }
            
            if (next_idx < n) {
                pq.push({val + nums[next_idx], next_idx + 1});
            }
        }
        
        return ans;
    }
};