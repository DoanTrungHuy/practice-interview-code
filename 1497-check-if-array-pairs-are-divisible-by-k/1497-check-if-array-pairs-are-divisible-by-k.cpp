class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // (num1%k + num2%k) % k = 0
        // (num1%k + num2%k) = k
        // 0 <= num1, num2 <= k - 1
        // cnt[0] = cnt[0 + k] = cnt[0 + 0] = cnt[k + k] is even
        // pair valid: cnt[1], cnt[4] | etc
        
        unordered_map<long long, long long> cnt;
        
        for (int num : arr) {
            cnt[((num*1LL) % k*1LL + k*1LL) % k*1LL]++;
        }
        
        if (cnt[0] & 1) {
            return false;
        }
        
        for (int d = 1; d <= k - 1; ++d) {
            if (cnt[d] != cnt[k - d]) {
                return false;
            }
        }
        
        return true;
    }
};