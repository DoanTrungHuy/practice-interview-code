using vi = vector<int>;

class DSU {
private:
    vi parent;
    int n;
    
public:
    DSU(int n = 0) {
        this->n = n;
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    bool _union(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) {
            return false;
        }
        
        parent[u] = v;
        return true;
    }
};

class Solution {
private:
    int n;
    vector<vi> edges;
    
public:
    int calc_mst(int i, int p = -1) {
        DSU dsu(n);
        int s = 0;
        int c = 0;
        
        if (p != -1) {
            s += edges[p][2];
            dsu._union(edges[p][0], edges[p][1]);
            c++;
        }
        
        int m = edges.size();
        
        for (int j = 0; j < m; ++j) {
            if (i == j) {
                continue;
            }
            if (dsu._union(edges[j][0], edges[j][1])) {
                s += edges[j][2];
                c++;
            }
            if (c == n - 1) {
                break;
            }
        }
        
        if (c != n - 1) {
            return INT_MAX;
        }
        
        return s;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vi>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        this->n = n;
        
        sort(edges.begin(), edges.end(), [&](const vi &a, const vi &b){
            return a[2] < b[2];
        });
        
        this->edges = edges;
        
        int ot_mst = calc_mst(-1);
        vi critical, not_critical;
        
        for (int i = 0; i < m; ++i) {
            if (calc_mst(i) > ot_mst) {
                critical.push_back(edges[i][3]);
            }
            else if (calc_mst(-1, i) == ot_mst) {
                not_critical.push_back(edges[i][3]);
            }
        }
        
        return {critical, not_critical};
    }
};