using ll = long long;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> us;
        sort(nums.begin(), nums.end());
        
        for (int a = 0; a < n - 3; ++a) {
            for (int b = a + 1; b < n - 2; ++b) {
                int c = b + 1;
                int d = n - 1;
                ll remaining = (ll)(target - (ll)(nums[a] + nums[b]));
                while (c < d) {
                    if ((ll)(nums[c] + nums[d]) == remaining) {
                        us.insert({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                    }
                    else if (nums[c] + nums[d] > remaining) {
                        d--;
                    }
                    else {
                        c++;
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        
        for (const auto arr : us) {
            ans.push_back(arr);
        }
        
        return ans;
    }
};