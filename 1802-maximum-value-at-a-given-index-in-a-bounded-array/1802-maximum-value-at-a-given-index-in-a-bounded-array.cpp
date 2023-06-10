using ll = long long;

class Solution {
public:
    ll sum(ll element, ll space) {
        if (element >= space) {
            ll remain = element - space;
            return element*(element + 1)/2 - (remain)*(remain + 1)/2;
        }
        else {
            ll remain = space - element;
            return element*(element + 1)/2 + remain;
        }
    }
    
    int maxValue(int n, int index, int maxSum) {
        ll left = 1, right = maxSum;
        ll spaceLeft = index;
        ll spaceRight = n - 1 - index;
        ll res = 0;
        
        while (left <= right) {
            ll mid = left + (right - left)/2;
            ll element = mid - 1;
            
            ll total = sum(element, spaceLeft) + 1LL*mid + sum(element, spaceRight);
            
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