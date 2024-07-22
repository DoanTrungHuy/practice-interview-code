class Solution {
private:
    vector<int> parent, size;
    
public:
    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]); 
    }
    
    void _union(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) {
            return;
        }
        
        if (u > v) {
            swap(u, v);
        }
        
        parent[u] = v;
        size[v] += size[u];
    }
    
    int validSubarraySize(vector<int>& nums, int threshold) {
        // num > threshold / k
        
        const int n = nums.size();
        parent.resize(n);
        size.resize(n, 1);
        
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            pq.push({nums[i], i});
        }
        
        set<int> us;
        
        while (!pq.empty()) {
            auto [num, i] = pq.top();
            pq.pop();
            
            us.insert(i);
            
            if (us.count(i - 1)) {
                _union(i, i - 1);
            }
            
            if (us.count(i + 1)) {
                _union(i, i + 1);
            }
            
            int k = size[find(i)];
            
            if (num*k > threshold) {
                return k;
            }
        }
        
        return -1;
    }
};