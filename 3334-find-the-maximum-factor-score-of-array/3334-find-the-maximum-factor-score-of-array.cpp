using ll = long long;

class Solution {
public:
    ll maxScore(vector<int>& nums) {
        const ll n = nums.size();
        
        auto lcm = [](ll a, ll b) -> ll {
            return (a / gcd(a, b)) * b;
        };
        
        ll ans = 0, tg = nums[0], tl = nums[0];

        for (ll i = 1; i < n; ++i) {
            tg = gcd(tg, nums[i]);
            tl = lcm(tl, nums[i]);
        }

        ans = max(ans, (ll)tg * tl);
        
        for (ll i = 0; i < n; ++i) {
            ll cd = 0, cl = 1;
            
            for (ll j = 0; j < n; ++j) {
                if (i != j) {
                    cd = (cd == 0) ? nums[j] : gcd(cd, nums[j]);
                    cl = lcm(cl, nums[j]);
                }
            }
            
            ans = max(ans, (ll)cd * cl);
        }
        
        return ans;
    }
};