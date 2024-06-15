class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Ưu tiên những dự án có thể mua được  -> sort capital
        // Dự án mình có thể mua được thì mình phải max profit  ->  heap
        
        const int n = profits.size();
        
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> sav_profit;
        int j = 0;
        
        while (k--) {
            while (j < n and projects[j].first <= w) {
                sav_profit.push(projects[j].second);
                j++;
            }
            if (sav_profit.empty()) {
                break;
            }
            w += sav_profit.top();
            sav_profit.pop();
        }
        
        return w;
    }
};