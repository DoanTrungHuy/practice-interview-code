class Solution {
private:
    vector<int> pref, suff;
    vector<int> arr;
    int n;
    
public:
    bool f(int x) {
        for (int i = 0; i < n - x + 1; i++) {
            int l = i - 1;
            int r = i + x;
            
            int left_bound = l < 0 ? INT_MIN : arr[l];
            int right_bound = r >= n ? INT_MAX : arr[r];
            
            if (left_bound <= right_bound) {
                if (l >= 0 && r < n && suff[r] == n - r && pref[l] == l + 1) {
                    return true;
                }
                else if (l < 0 && suff[r] == n - r) {
                    return true;
                }
                else if (r >= n && pref[l] == l + 1) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    int findLengthOfShortestSubarray(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        pref.resize(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] <= arr[i]) {
                pref[i] = pref[i - 1] + 1;
            }
        }
        
        suff.resize(n, 1);
        
        for (int i = n - 1; i >= 1; --i) {
            if (arr[i] >= arr[i - 1]) {
                suff[i - 1] = suff[i] + 1;
            }
        }
        
        int left = 0;
        int right = n;
        int ans = n;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            
            if (f(mid)) {
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