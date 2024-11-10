using ll = long long;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<ll, ll> cnt, sos;

        ll ans = 0;
        
        for (int num : nums) {
            ll curr_cnt = 1LL, curr_sum = num*1LL;

            for (int d : {-1, 1}) {
                curr_cnt = (curr_cnt + cnt[num + d])%MOD;
                curr_sum = (curr_sum + sos[num + d] + (cnt[num + d]*num)%MOD)%MOD;
            }
            
            cnt[num] = (cnt[num] + curr_cnt)%MOD;
            sos[num] = (sos[num] + curr_sum)%MOD;

            ans = (ans + curr_sum)%MOD;
        }
        
        return ans;
    }
};