class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        // n = 10^5 -> Time: O(N) -> 1 for (Chu yeu chay 1s - (10^5 -> 10^6))
        int total = 0;
        
        for (int r = 0; r < k; ++r) {
            total += arr[r];
        }
        
        int ans = (total / k >= threshold);
        
        for (int r = k; r < n; ++r) {
            total += arr[r] - arr[r - k];
            ans += (total / k >= threshold);
        }
        
        return ans;
    }
};