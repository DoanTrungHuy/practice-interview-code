class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int n = original.size();
        const int INF = 1e9;
        const int MAX_LEN_CHAR = 26;
        vector<vector<long long>> dist(MAX_LEN_CHAR, vector<long long>(MAX_LEN_CHAR, INF));
        
        for (int i = 0; i < n; ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];
            dist[u][v] = min(dist[u][v], 1LL*w);
        }
        
        for (int k = 0; k < MAX_LEN_CHAR; ++k) {
            for (int u = 0; u < MAX_LEN_CHAR; ++u) {
                for (int v = 0; v < MAX_LEN_CHAR; ++v) {
                    if (u == v) {
                        dist[u][v] = 0;
                    } 
                    if (u != v && dist[u][k] != INF && dist[k][v] != INF) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        
        const int m = source.size();
        
        long long ans = 0;
        
        for (int i = 0; i < m; ++i) {
            if (dist[source[i] - 'a'][target[i] - 'a'] == INF) {
                return -1;
            }            
            
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        
        return ans;
    }
};