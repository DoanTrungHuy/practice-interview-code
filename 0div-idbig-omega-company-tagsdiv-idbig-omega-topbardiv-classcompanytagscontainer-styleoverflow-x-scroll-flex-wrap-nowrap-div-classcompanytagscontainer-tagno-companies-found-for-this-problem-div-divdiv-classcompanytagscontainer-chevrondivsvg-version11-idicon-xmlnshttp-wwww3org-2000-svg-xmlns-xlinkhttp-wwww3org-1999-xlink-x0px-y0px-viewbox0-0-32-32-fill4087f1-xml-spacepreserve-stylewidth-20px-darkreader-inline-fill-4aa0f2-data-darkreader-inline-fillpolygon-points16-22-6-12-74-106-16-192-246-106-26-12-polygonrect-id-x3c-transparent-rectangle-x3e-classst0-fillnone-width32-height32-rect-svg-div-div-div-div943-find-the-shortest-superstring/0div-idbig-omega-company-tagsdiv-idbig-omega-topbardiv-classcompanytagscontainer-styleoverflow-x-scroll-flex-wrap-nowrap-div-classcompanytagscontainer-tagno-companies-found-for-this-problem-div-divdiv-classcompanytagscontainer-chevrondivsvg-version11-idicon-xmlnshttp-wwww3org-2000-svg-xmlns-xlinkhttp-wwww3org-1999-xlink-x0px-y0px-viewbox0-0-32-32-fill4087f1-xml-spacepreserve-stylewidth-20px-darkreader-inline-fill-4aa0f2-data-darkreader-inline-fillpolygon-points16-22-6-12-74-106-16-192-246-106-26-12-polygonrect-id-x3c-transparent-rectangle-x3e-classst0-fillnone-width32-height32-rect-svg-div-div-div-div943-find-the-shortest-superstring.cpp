const int MN = 12;
int memo[MN][1 << MN];
int next_vertex[MN][1 << MN];

class Solution {
private:
    vector<string> words;
    int n;
    
public:
    int sub_duplicate(string &s1, string &s2) {
        int ans = -1;
        int sz1 = s1.size();
        int sz2 = s2.size();

        for (int i = 0; i <= min(sz1, sz2); ++i) {
            if (s1.substr(sz1 - i, i) == s2.substr(0, i)) {
                ans = i;
            }
        }
        
        return ans;
    }
    
    int dp(int u, int mask) {
        if (mask == ((1 << n) - 1)) {
            return 0;
        }
        
        if (memo[u][mask] != -1) {
            return memo[u][mask];
        }
        
        int min_path_tv = 1e9;
        
        for (int v = 0; v < n; ++v) {
            if (u == v) {
                continue;
            }
            if ((mask & (1 << v)) == 0) {
                string s1 = words[u];
                string s2 = words[v];
                int duplicate = sub_duplicate(s1, s2);
                
                int cur_path_tv = s2.size() - duplicate + dp(v, mask ^ (1 << v));
                
                if (cur_path_tv < min_path_tv) {
                    min_path_tv = cur_path_tv;
                    next_vertex[u][mask] = v;
                }
            }
        }
        
        return memo[u][mask] = min_path_tv;
    }
    
    string shortestSuperstring(vector<string>& words) {
        this->words = words;
        this->n = words.size();
        memset(memo, -1, sizeof(memo));
        memset(next_vertex, -1, sizeof(next_vertex));
        
        int ans = 1e9;
        int srt = -1;
        
        for (int u = 0; u < n; ++u) {
            int cur = words[u].size() + dp(u, 1 << u);
            
            if (cur < ans) {
                ans = cur;
                srt = u;
            }
        }
        
        string shortest_superstring = words[srt];
        int mask = 1 << srt;
        
        while (true) {
            int nxt = next_vertex[srt][mask];
            if (nxt == -1) {
                break;
            }
            int duplicate = sub_duplicate(words[srt], words[nxt]);
            shortest_superstring += words[nxt].substr(duplicate);
            srt = nxt;
            mask |= (1 << nxt);
        }
        
        return shortest_superstring;
    }
};