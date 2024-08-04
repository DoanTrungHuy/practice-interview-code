class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double left = 0.0, right = 1.0;
        int n = arr.size();
        
        while (left < right) {
            double mid = (left + right) / 2;
            int cnt = 0;
            int a = 0, b = 0;
            double max_fraction = 0.0;
            
            for (int i = 0, j = 1; i < n; ++i) {
                while (j < n && arr[i] > mid * arr[j]) {
                    j++;
                }
                cnt += n - j;
                if (j < n && arr[i] * 1.0 / arr[j] > max_fraction) {
                    a = i;
                    b = j;
                    max_fraction = arr[i] * 1.0 / arr[j];
                }
            }
            
            if (cnt == k) {
                return {arr[a], arr[b]};
            } 
            else if (cnt > k) {
                right = mid;
            } 
            else {
                left = mid;
            }
        }
        
        return {-1, -1};
    }
};
