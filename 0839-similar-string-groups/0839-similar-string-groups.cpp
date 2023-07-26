class Solution {
private:
    vector<int> parent;
    int group;
    
public:
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }    
        return parent[u];
    }
    
    void _union(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u != v) {
            parent[u] = v;
            group--;
        }
    }
    
    bool isSimilar(string a, string b) {
        int cnt = 0;
        int n = a.size();
        
        for (int i = 0; i < n; ++i) {
            cnt += a[i] != b[i];
            if (cnt > 2) {
                return false;
            }
        }
        
        return cnt == 0 or cnt == 2;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        this->group = n;
        parent.resize(group);
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    _union(i, j);
                }
            }
        }
        
        return group;
    }
};