using ll = long long;

class Solution {
private:
    vector<int> batteries;
    int n;
    
public:
    bool f(ll x) {
        ll limit_time = x, total = 0;
        
        for (int batterie : batteries) {
            total += min(batterie*1LL, limit_time);
        }
        
        return total >= (limit_time*n);
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        this->n = n;
        this->batteries = batteries;
        
        ll left = 1, right = 1e14;
        ll ans = 1;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            if (f(mid)) {
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