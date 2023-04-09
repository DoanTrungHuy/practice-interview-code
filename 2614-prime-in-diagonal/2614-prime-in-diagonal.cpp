class Solution {
public:
    bool prime(int num) {
        if (num < 2) {
            return false;
        }
        
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxPrime = 0;
        while (i < n and j < n) {
            if (prime(nums[i][j])) {
                maxPrime = max(maxPrime, nums[i][j]);
            }
            i++, j++;
        }
        i = 0, j = n - 1;
        while (i < n and j >= 0) {
            if (prime(nums[i][j])) {
                maxPrime = max(maxPrime, nums[i][j]);
            }
            i++;
            j--;
        }
        return maxPrime;
    }
};