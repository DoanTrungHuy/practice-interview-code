class Solution {
private:
    vector<vector<int>> adj;
    vector<int> indegree;
    int n, k;
    vector<vector<int>> relations;
    
public:
    int popcount(int num) {
        int cnt = 0;
        while (num) {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
    vector<vector<int>> combination(vector<int> &nextState, int k) {
        int m = nextState.size();
        vector<vector<int>> ans;
        
        for (int mask = 0; mask < (1 << m); ++mask) {
            if (popcount(mask) != k) {
                continue;
            }
            vector<int> tmp;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    tmp.push_back(nextState[i]);
                }
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
    void helper(vector<int> &nextState, int &nextMask, int step) {
        for (int i = 0; i < nextState.size(); ++i) {
            int prevCourse = nextState[i];
            nextMask ^= (1 << prevCourse);
            for (int nextCourse : adj[prevCourse]) {
                indegree[nextCourse] += step;
            }
        }
    }
    
    int memo[1 << 15];
    
    int dp(int mask) {
        if (mask == ((1 << n) - 1)) {
            return 0;
        }
        
        if (memo[mask] != -1) {
            return memo[mask];
        }
        
        vector<int> nextState;
        
        for (int course = 0; course < n; ++course) {
            if (indegree[course] == 0 and ((mask & (1 << course)) == 0)) {
                nextState.push_back(course);
            }
        }
        
        int ans = n;
        
        if (nextState.size() <= k) {
            int nextMask = mask;
            
            helper(nextState, nextMask, -1);
            ans = min(ans, 1 + dp(nextMask));
            helper(nextState, nextMask, +1);
        }
        else {
            vector<vector<int>> comb = combination(nextState, k);
            
            for (vector<int> &C : comb) {               
                int nextMask = mask;
                
                helper(C, nextMask, -1);
                ans = min(ans, 1 + dp(nextMask));
                helper(C, nextMask, +1);
            }
        }
        
        return memo[mask] = ans;
    }
    
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        this->relations = relations;
        this->n = n, this->k = k;
        adj.resize(n), indegree.resize(n);
        memset(memo, -1, sizeof(memo));
        
        for (vector<int> relation : relations) {
            int u = relation[0];
            int v = relation[1];
            u--, v--;
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        return dp(0);
    }
};