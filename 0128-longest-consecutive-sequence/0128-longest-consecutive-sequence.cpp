class DSU {
private:
    unordered_map<int, int> parent, rank;
    int maxRank;

public:
    DSU() {
        maxRank = 1;
    }

    void add(int u) {
        parent[u] = u;
        rank[u] = 1;
    }

    int find(int u) {
        if (u == parent[u]) {
            return parent[u];
        }
        return parent[u] = find(parent[u]);
    }

    void _union(int u, int v) {
        if (!parent.count(v)) {
            return;
        }

        int pu = find(u);
        int pv = find(v);

        if (pu != pv) {
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
                rank[pu] += rank[pv];
            }
            else {
                parent[pu] = pv;
                rank[pv] += rank[pu];
            }
            maxRank = max({maxRank, rank[pu], rank[pv]});
        } 
    }

    int getMaxRank() {
        return maxRank;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();

        if (n <= 1) {
            return n;
        }

        DSU dsu;

        unordered_set<int> us(nums.begin(), nums.end());

        for (int num : us) {
            dsu.add(num);
            dsu._union(num, num - 1);
            dsu._union(num, num + 1);
        }

        return dsu.getMaxRank();
    }
};