class Solution {
public:
    int root[1001];
    int res = 0;
    int findRoot(int v) {
        if (v == root[v]) {
            return v;
        }
        return root[v] = findRoot(root[v]);
    }
    void unionSet(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            root[v] = u;
            res++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
        for (int i = 0; i < n - 1; ++i) {
            int x1 = stones[i][0];
            int y1 = stones[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = stones[j][0];
                int y2 = stones[j][1];
                if (x1 == x2 || y1 == y2) {
                    unionSet(i, j);
                }
            }
        }
        return res;
    }
};