class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        const int MN = 2e5 + 10;
        using pii = pair<int, int>;
        vector<pii> events;
        unordered_map<int, int> um;
        
        set<int> points;
        
        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
            points.insert(nums[i]);
            events.push_back({nums[i] - k, 1});
            points.insert(nums[i] - k);
            events.push_back({nums[i] + k + 1, -1});
            points.insert(nums[i] + k);
        }
        
        sort(events.begin(), events.end());
        
        const int m = events.size();
        int ans = 0, line = 0, i = 0;
        
        // |--------------|
        //         |-----------------|
        //    |---------------------------------|
        //    2    3      2          1
        
        for (int p : points) {
            int cnt_p = 0;
            
            if (um.count(p)) {
                cnt_p = um[p];
            }
            
            while (i < m && events[i].first <= p) {
                line += events[i++].second;
            }
            
            ans = max(ans, cnt_p + min(numOperations, line - cnt_p));
        }
        
        return ans;
    }
};