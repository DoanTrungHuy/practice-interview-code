class DSU {
private:
    vector<int> parent;
    
public:
    DSU() {
        
    }
    
    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void _union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> groups;
        const int n = s.size();
        DSU dsu(n);
        
        for (vector<int> p : pairs) {
            dsu._union(p[0], p[1]);
        }
        
        for (int i = 0; i < n; ++i) {
            groups[dsu.find(i)].push_back(i);
        }
        
        for (auto [_, group] : groups) {
            priority_queue<char, vector<char>, greater<char>> pq;
            
            for (int index : group) {
                pq.push(s[index]);
            }
            
            for (int index : group) {
                s[index] = pq.top();
                pq.pop();
            }
        }
        
        return s;
    }
};