class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU() {
        
    }
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        rank.resize(n, 1);
    }
    
    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void _union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu == pv) {
            return;
        }
        
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu] += rank[pv];
        }
        else {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> hash;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (!hash.count(accounts[i][j])) {
                    hash[accounts[i][j]] = i;
                }
                else {
                    dsu._union(hash[accounts[i][j]], i);
                }
            }
        }
        
        unordered_map<int, set<string>> users;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                users[dsu.find(i)].insert(accounts[i][j]);
            } 
        }
        
        vector<vector<string>> ans;
        
        for (auto [pos_user, gmails] : users) {
            vector<string> tmp = {accounts[pos_user][0]};
            for (string gmail : gmails) {
                tmp.push_back(gmail);
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};