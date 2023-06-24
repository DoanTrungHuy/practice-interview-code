using ll = long long;

class Solution {
public:
    ll f(vector<int> &nums, vector<int> &cost, int medium) {
        int n = nums.size();
        ll total = 0;
        
        for (int i = 0; i < n; ++i) {
            total += 1LL*abs(nums[i] - medium)*cost[i];
        }
        
        return total;
    }
    
    ll minCost(vector<int>& nums, vector<int>& cost) {
        int left = 1, right = 1e6;
        ll ans = 0;
        
        while (left < right) {
            int x = (left + right) / 2;
            ll y1 = f(nums, cost, x);
            ll y2 = f(nums, cost, x + 1);
            if (y1 < y2) {
                right = x;    
            }
            else {
                ans = y2;
                left = x + 1;
            }
        }
        
        return ans;
    }
};