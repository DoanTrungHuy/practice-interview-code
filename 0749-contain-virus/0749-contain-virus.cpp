class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU() {
        
    }
    
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }
    
    void add(int u) {
        parent[u] = u;
    }
    
    int find(int u) {
        if (parent[u] == -1) {
            return -1;
        }
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
            rank[pu] += rank[pv];
            parent[pv] = pu;
        }
        else {
            rank[pv] += rank[pu];
            parent[pu] = pv;
        }
    }
    
    int get_rank(int u) {
        return rank[find(u)];
    }
    
    void set_parent_of(int u, int val) {
        parent[u] = val;
    }
};

class Solution {
private:
    int m, n;
    
public:
    int containVirus(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        DSU dsu(n*m);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    int fc = i*n + j;
                    int fu = fc - n;
                    int fl = fc - 1;
                    
                    dsu.add(fc);
                    
                    if (i - 1 >= 0 and grid[i - 1][j]) {
                        dsu._union(fc, fu);
                    }
                    if (j - 1 >= 0 and grid[i][j - 1]) {
                        dsu._union(fc, fl);
                    }
                }
            }
        }
        
        int ans = 0;
        const int DIR[5] = {-1, 0, 1, 0, -1};
        
        while (true) {
            map<int, set<pair<int, int>>> partition_affect;
            map<int, int> cnt_partition;
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) { 
                    if (!grid[i][j] or dsu.find(n*i + j) == -1) {
                        continue;
                    }
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + DIR[k];
                        int nj = j + DIR[k + 1];
                        
                        if (!isValid(ni, nj) or grid[ni][nj]) {
                            continue;
                        }
                        
                        partition_affect[dsu.find(i*n + j)].insert({ni, nj});
                        cnt_partition[dsu.find(i*n + j)]++;
                    }
                }
            }
            
            if (partition_affect.size() == 0) {
                break;
            }
            
            int largest_partition = INT_MIN;
            int max_num = INT_MIN;
            
            for (auto [num, set_in_partition] : partition_affect) {
                if (largest_partition < (int)set_in_partition.size()) {
                    largest_partition = (int)set_in_partition.size();
                    max_num = num;
                }
            }
            
            ans += cnt_partition[max_num];
            
            dsu.set_parent_of(max_num, -1);
            
            for (auto [key, partition] : partition_affect) {
                if (key == max_num) {
                    continue;
                }
                for (auto [i, j] : partition) {
                    grid[i][j] = 1;
                    dsu.add(i*n + j);
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + DIR[k];
                        int nj = j + DIR[k + 1];

                        if (!isValid(ni, nj)) {
                            continue;
                        }

                        if (dsu.find(ni*n + nj) == -1) {
                            continue;
                        }

                        dsu._union(i*n + j, ni*n + nj);
                    }
                }
            }
        }
        
        return ans;
    }
    
    bool isValid(int i, int j) {
        return 0 <= i and i < m and 0 <= j and j < n;
    }
};