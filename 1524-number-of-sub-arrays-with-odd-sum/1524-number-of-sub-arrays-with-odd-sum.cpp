class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
        int res = 0;
        int sum = 0;
        const int mod = 1e9 + 7;
        
        for (int num : arr) {
            sum += num;
            if (sum & 1) {
                res = (res + even) % mod;
                odd++;
            }
            else {
                res = (res + odd) % mod;
                even++;
            }
        }
        
        return res;
    }
};