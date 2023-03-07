class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        for (int x = 1; x <= n; ++x) {
            vector<int> tmp(n);
            for (int i = 0; i < n; ++i) {
                tmp[i] = nums[(i + x) % n];
            }

            bool flag = true;
            
            for (int i = 0; i < n - 1; ++i) {
                if (!(tmp[i] <= tmp[i + 1])) {
                    flag = false;
                }
            }
            
            if (flag) {
                return true;
            }
        }
        
        return false;
    }
};