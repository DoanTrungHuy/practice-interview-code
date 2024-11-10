class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        const int MN = 2e5 + 10;
        using pii = pair<int, int>;
        unordered_map<int, int> um, events;
        
        set<int> points;
        
        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
            events[nums[i] - k]++;
            events[nums[i] + k + 1]--;
            points.insert(nums[i]);
            points.insert(nums[i] - k);
            points.insert(nums[i] + k + 1);
        }
        
        int ans = 0, line = 0;
        
        // |--------------|
        //         |-----------------|
        //    |---------------------------------|
        //    2    3      2          1
        
        for (int p : points) {
            line += events[p];
            ans = max(ans, um[p] + min(numOperations, line - um[p]));
        }
        
        return ans;
    }
};