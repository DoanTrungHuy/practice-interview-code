class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long left = 1;
        long long right = m*n;
        long long ans = 0;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long cnt = 0;
            
            for (int i = 1; i <= m; ++i) {
                cnt += min(mid / i, n*1LL);
            }
            
            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};