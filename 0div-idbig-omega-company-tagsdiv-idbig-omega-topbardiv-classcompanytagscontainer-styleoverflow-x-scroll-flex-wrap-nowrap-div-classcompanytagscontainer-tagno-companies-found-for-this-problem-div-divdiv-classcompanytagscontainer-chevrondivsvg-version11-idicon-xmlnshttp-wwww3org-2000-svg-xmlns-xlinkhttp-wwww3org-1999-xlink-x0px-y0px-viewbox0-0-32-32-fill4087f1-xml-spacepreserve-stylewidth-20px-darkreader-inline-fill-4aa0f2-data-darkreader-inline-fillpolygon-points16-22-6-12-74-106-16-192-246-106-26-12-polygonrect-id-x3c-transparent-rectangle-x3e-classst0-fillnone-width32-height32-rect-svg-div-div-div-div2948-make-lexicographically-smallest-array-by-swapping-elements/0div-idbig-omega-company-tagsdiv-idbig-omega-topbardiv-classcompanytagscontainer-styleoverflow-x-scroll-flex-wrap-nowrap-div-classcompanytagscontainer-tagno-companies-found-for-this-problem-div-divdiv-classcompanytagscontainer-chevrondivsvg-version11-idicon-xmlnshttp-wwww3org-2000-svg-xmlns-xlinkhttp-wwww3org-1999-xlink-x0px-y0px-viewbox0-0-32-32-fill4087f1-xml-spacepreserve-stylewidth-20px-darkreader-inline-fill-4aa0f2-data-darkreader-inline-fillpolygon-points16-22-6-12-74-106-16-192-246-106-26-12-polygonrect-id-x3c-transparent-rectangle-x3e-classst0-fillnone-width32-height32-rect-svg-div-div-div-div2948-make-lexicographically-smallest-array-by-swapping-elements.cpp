class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> tmp = nums;
        const int n = tmp.size();
        sort(tmp.begin(), tmp.end());
        int prev = tmp[0];
        
        map<int, vector<int>> grs;
        int j = 0;
        map<int, int> mp_idx;
        
        for (int i = 0; i < n; ++i) {
            if (tmp[i] - prev <= limit) {
                grs[j].push_back(tmp[i]);
                mp_idx[tmp[i]] = j;
            }
            else {
                j++;
                grs[j].push_back(tmp[i]);
                mp_idx[tmp[i]] = j;
            }
            prev = tmp[i];
        }
        
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = grs[mp_idx[nums[i]]].back();
            grs[mp_idx[nums[i]]].pop_back();
        }
        
        return ans;
    }
};