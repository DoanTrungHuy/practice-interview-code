using ll = long long;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        ll left = 1, right = maxSum;
        ll spaceLeft = index;
        ll spaceRight = n - 1 - index;
        ll res = 0;
        
        while (left <= right) {
            ll mid = left + (right - left)/2;
            ll sumLeft = 0, sumRight = 0, element = mid - 1;
            
            if (element >= spaceRight) {
                ll remain = element - spaceRight;
                sumRight = element*(element + 1)/2 - (remain)*(remain + 1)/2;
            }
            else {
                ll remain = spaceRight - element;
                sumRight = element*(element + 1)/2 + remain;
            }
            
            if (element >= spaceLeft) {
                ll remain = element - spaceLeft;
                sumLeft = element*(element + 1)/2 - (remain)*(remain + 1)/2;
            }
            else {
                ll remain = spaceLeft - element;
                sumLeft = element*(element + 1)/2 + remain;
            }
            
            ll total = sumLeft + 1LL*mid + sumRight;
            
            if (total <= maxSum) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return (int)res;
    }
};