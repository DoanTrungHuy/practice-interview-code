class Solution {
private:
    vector<vector<int>> events;
    int n;
    vector<int> starts;
    vector<vector<int>> memo;
    
public:
    int dp(int i, int k) {
        if (k == 0 or i >= n) {
            return 0;
        }
        
        if (memo[i][k] != -1) {
            return memo[i][k];
        }
        
        int j = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
        
        return memo[i][k] = max(
            dp(i + 1, k),
            dp(j, k - 1) + events[i][2]
        );
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        this->events = events;
        this->n = events.size();
        memo.resize(this->n + 1, vector<int>(k + 1, -1));
        
        for (auto event : events) {
            starts.push_back(event[0]);
        }
        
        return dp(0, k);
    }
};