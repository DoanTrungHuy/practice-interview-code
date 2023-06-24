using ll = long long;

class Solution {
private:
    vector<pair<int, int>> bag;
    int n;
    vector<int> cost;
    
public:
    ll minCost(vector<int>& nums, vector<int>& cost) {
        this->cost = cost;
        int n = cost.size();
        ll total = 0;
        
        for (int i = 0; i < n; ++i) {
            bag.push_back({nums[i], cost[i]});
            total += 1LL*cost[i];
        }
        
        sort(bag.begin(), bag.end());
        
        ll sumCurrent = 0;
        int medium = 0;
        int i = 0;
        
        while (sumCurrent <= total / 2 and i < n) {
            sumCurrent += 1L*bag[i].second;
            medium = bag[i].first;
            i++;
        }
        
        ll ans = 0LL;
        
        for (int i = 0; i < n; ++i) {
            ans += 1LL*abs(bag[i].first - medium)*bag[i].second;
        }
        
        return ans;
    }
};