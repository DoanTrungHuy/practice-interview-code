class Solution {
private:
    vector<long long int> pref;
    
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        unordered_map<long long, vector<int>> um[2];
        const int n = nums.size();
        pref.resize(n + 1);
        
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (um[0].count(k + num)) {
                for (int j : um[0][k + num]) {
                    ans = max(ans, pref[i + 1] - pref[j]);
                }
            }
            if (um[1].count(k - num)) {
                for (int j : um[1][k - num]) {
                    ans = max(ans, pref[i + 1] - pref[j]);
                }
            }
            um[0][+num].push_back(i);
            um[1][-num].push_back(i);
        }
        
        return ans == LLONG_MIN ? 0 : ans;
    }
};