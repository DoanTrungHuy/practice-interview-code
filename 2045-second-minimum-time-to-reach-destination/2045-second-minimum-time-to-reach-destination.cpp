#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int cnt_minimum_second = 0;
        vector<vector<int>> adj(n + 1);
        
        for (vector<int> &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        
        vector<int> dist(n + 1, INT_MAX);
        vector<int> second_dist(n + 1, INT_MAX);
        dist[1] = 0;
        
        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();
            
            if (u == n) {
                cnt_minimum_second++;
                if (cnt_minimum_second == 2) {
                    return du;
                }
            }
            
            for (int v : adj[u]) {
                int dv = du + time;
                if ((du / change) % 2 == 1) {
                    dv = du + change - (du % change) + time;
                }
                
                if (dv < dist[v]) {
                    swap(dist[v], dv);
                    pq.push({dist[v], v});
                }
                
                if (dv > dist[v] && dv < second_dist[v]) {
                    second_dist[v] = dv;
                    pq.push({second_dist[v], v});
                }
            }
        }
        
        return -1;
    }
};
