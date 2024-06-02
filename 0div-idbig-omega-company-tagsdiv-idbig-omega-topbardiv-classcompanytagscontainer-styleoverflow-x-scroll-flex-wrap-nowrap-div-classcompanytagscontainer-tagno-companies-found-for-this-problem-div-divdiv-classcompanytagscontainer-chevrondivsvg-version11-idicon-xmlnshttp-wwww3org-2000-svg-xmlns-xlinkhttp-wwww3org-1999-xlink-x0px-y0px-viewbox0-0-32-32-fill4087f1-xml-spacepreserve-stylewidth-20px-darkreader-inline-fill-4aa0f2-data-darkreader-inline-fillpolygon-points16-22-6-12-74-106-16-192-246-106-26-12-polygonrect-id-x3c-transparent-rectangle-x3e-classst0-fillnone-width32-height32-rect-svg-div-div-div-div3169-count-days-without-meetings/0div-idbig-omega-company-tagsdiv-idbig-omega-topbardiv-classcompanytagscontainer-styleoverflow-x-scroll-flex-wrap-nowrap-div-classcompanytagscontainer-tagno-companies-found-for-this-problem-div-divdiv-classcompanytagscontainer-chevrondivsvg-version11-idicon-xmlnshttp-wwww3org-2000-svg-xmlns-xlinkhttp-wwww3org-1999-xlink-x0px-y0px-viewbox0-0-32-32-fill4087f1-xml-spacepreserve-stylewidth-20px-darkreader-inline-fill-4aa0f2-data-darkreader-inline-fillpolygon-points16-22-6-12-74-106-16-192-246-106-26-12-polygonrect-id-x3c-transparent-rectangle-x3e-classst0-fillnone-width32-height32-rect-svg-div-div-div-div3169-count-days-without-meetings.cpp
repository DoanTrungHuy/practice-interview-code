class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        const int n = meetings.size();
        vector<vector<int>> ans;
        ans.push_back(meetings[0]);
        
        for (int i = 1; i < n; ++i) {
            if (meetings[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], meetings[i][1]);
            }
            else {
                ans.push_back(meetings[i]);
            }
        }
        
        return ans;
    }
    
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> iterval = merge(meetings);
        
        for (vector<int> m : iterval) {
            days -= m[1] - m[0] + 1;
        }
        
        return days;
    }
};