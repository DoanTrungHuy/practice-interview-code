class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<int, int> um;
        
        for (char c : s) {
            um[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for (const auto &[v, c] : um) {
            pq.push({c, v});
        }
        
        string ans = "";
        
        while (pq.size() > 1) {
            auto [c1, v1] = pq.top();
            pq.pop();
            
            auto [c2, v2] = pq.top();
            pq.pop();
            
            c1--, c2--;
            ans.push_back(v1);
            ans.push_back(v2);
            
            if (c1 > 0) {
                pq.push({c1, v1});
            }
            
            if (c2 > 0) {
                pq.push({c2, v2});
            }
        }
        
        if (!pq.empty()) {
            if (pq.top().first > 1) {
                return "";
            }
            else {
                return ans + pq.top().second;
            }
        }
        
        return ans;
    }
};