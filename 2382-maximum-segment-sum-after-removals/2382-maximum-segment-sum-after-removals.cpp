using ll = long long;

class DSU {
private:
    vector<ll> parent, sum;
    ll maxSegmentSum;
    
public:
    DSU(vector<int> nums) {
        int n = nums.size();
        parent.resize(n), sum.resize(n);
        maxSegmentSum = 0;
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sum[i] = 1LL*nums[i];
        } 
    }
    
    ll find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu != pv) {
            parent[pv] = pu;
            sum[pu] += sum[pv];
            maxSegmentSum = max(maxSegmentSum, sum[pu]);
        }
    }
    
    ll getMaxSegmentSum() {
        return maxSegmentSum;
    }
    
    void setMaxSegmentSum(ll val) {
        maxSegmentSum = max(maxSegmentSum, val);
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        DSU dsu(nums);
        int n = removeQueries.size();
        vector<ll> ans(n);
        vector<bool> visited(n, false);
        
        for (int i = n - 1; i >= 0; --i) {
            int positive = removeQueries[i];
            
            ans[i] = dsu.getMaxSegmentSum();
            visited[positive] = true;
            dsu.setMaxSegmentSum(nums[positive]);
            
            if (positive - 1 >= 0 and visited[positive - 1]) {
                dsu.merge(positive, positive - 1);
            }
            if (positive + 1 < n and visited[positive + 1]) {
                dsu.merge(positive, positive + 1);
            }
        }
        
        return ans;
    }
};