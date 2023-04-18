class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        const int diff = arr[1] - arr[0];
        
        for (int i = 2; i < n; ++i) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
};