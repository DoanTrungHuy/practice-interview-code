class Solution {
public:
    int mySqrt(int x) {
        using ll = long long;
        ll left = 0;
        ll right = x;
        ll ans = x;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            if (mid*mid <= x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};