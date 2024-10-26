class Solution {
private:
    vector<vector<int>> nA;
    vector<int> ans;

public:
    int dfs(int node) {
        int cnt = 1;
        for (int child : nA[node]) {
            cnt += dfs(child);
        }
        return ans[node] = cnt;
    };

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        const int n = parent.size();
        vector<int> nP = parent;
        
        for (int i = 1; i < n; ++i) {
            int curr = parent[i];
            while (curr != -1 && s[curr] != s[i]) {
                curr = parent[curr];
            }
            if (curr != -1) {
                nP[i] = curr;
            }
        }

        nA.resize(n);
        
        for (int i = 1; i < n; ++i) {
            nA[nP[i]].push_back(i);
        }

        ans.resize(n, 0);
        dfs(0);
        
        return ans;
    }
};
