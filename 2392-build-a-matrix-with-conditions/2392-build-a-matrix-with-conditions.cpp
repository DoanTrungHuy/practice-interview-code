const int MN = 401;

int indegree_r[MN] = {};
int indegree_c[MN] = {};

class Solution {
private:
    vector<vector<int>> adj_row, adj_col;
    vector<int> visited;
    
public:
    bool dfs(vector<vector<int>> &adj, int u) {
        visited[u] = 1;
        
        for (int v : adj[u]) {
            if (visited[v] == 0) {
                if (dfs(adj, v)) {
                    return true;
                }
            }
            else if (visited[v] == 1) {
                return true;
            }
        }
        
        visited[u] = 2;
        
        return false;
    }
    
    void bfs(vector<vector<int>> &adj, queue<int> &mq, int indegree[], vector<int> &order) {
        int times = 0;
        
        while (mq.size()) {
            int u = mq.front();
            mq.pop();
            
            order[u] = times++;
            
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    mq.push(v);
                }
            }
        }
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Topo
        
        adj_row.resize(k + 1);
        adj_col.resize(k + 1);
        
        memset(indegree_r, 0, sizeof indegree_r);
        memset(indegree_c, 0, sizeof indegree_c);
        
        set<vector<int>> s1(rowConditions.begin(), rowConditions.end());
        
        for (vector<int> r : s1) {
            adj_row[r[0]].push_back(r[1]);
            indegree_r[r[1]]++;
        }
        
        set<vector<int>> s2(colConditions.begin(), colConditions.end());
        
        for (vector<int> c : s2) {
            adj_col[c[0]].push_back(c[1]);
            indegree_c[c[1]]++;
        }
        
        queue<int> mq1, mq2;
        
        for (int i = 1; i <= k; ++i) {
            if (indegree_r[i] == 0) {
                mq1.push(i);
            }
            if (indegree_c[i] == 0) {
                mq2.push(i);
            }
        }
        
        visited.resize(k + 1);
        
        for (int i = 1; i <= k; ++i) {
            if (!visited[i]) {
                if (dfs(adj_col, i)) {
                    return {};
                }
            }
        }
        
        fill(visited.begin(), visited.end(), 0);
        
        for (int i = 1; i <= k; ++i) {
            if (!visited[i]) {
                if (dfs(adj_row, i)) {
                    return {};
                }
            }
        }
        
        vector<int> row_of_num(k + 1);
        vector<int> col_of_num(k + 1);
        
        bfs(adj_row, mq1, indegree_r, row_of_num);
        bfs(adj_col, mq2, indegree_c, col_of_num);
        
        vector<vector<int>> mat(k, vector<int>(k));
        
        for (int i = 1; i <= k; ++i) {
            mat[row_of_num[i]][col_of_num[i]] = i;
        }
        
        return mat;
    }
};