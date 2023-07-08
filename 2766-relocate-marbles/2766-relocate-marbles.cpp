class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> us;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            us.insert(nums[i]);
        }
        
        for (int i = 0; i < moveFrom.size(); ++i) {
            if (us.find(moveFrom[i]) != us.end()) {
                us.erase(moveFrom[i]);
                us.insert(moveTo[i]);
            }
        }
        
        vector<int> ans;
        
        for (int x : us) {
            ans.push_back(x);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};