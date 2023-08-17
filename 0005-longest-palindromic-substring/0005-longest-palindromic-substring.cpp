using ull = unsigned long long;
ull base = 256;
const ull MOD = 1e9 + 7;
const int MN = 1005;
ull h[2][MN], p[MN];

class Solution {
private:
    string s, t;
    int n;
    
public:
    ull get_hash(int t, int i, int j) {
        return (h[t][j] - h[t][i - 1]*p[j - i + 1] + MOD*MOD) % MOD;
    }
    
    int get_index(int m) {
        for (int l = 1; l <= n - m + 1; ++l) {
            int r = l + m - 1;
            if (get_hash(0, l, r) == get_hash(1, n - r + 1, n - l + 1)) {
                return l - 1;
            }
        }
        return -1;
    }
    
    string longestPalindrome(string s) {
        memset(h, 0, sizeof(h));
        memset(p, 0, sizeof(p));
        
        this->s = s;
        this->t = s;
        
        this->n = s.size();
        reverse(t.begin(), t.end());
        
        p[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            h[0][i] = (h[0][i - 1]*base + s[i - 1]) % MOD;
            h[1][i] = (h[1][i - 1]*base + t[i - 1]) % MOD;
            p[i] = (p[i - 1]*base) % MOD;
        }
        
        int left = 1;
        int right = n / 2;
        int len_best = 1;
        int idx_best = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            int idx = get_index(2*mid);
            
            if (idx == -1) {
                right = mid - 1;
            }
            else {
                if (2*mid > len_best) {
                    len_best = 2*mid;
                    idx_best = idx;
                }
                left = mid + 1;
            }
        }
        
        left = 1;
        right = n / 2;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            int idx = get_index(2*mid + 1);
            
            if (idx == -1) {
                right = mid - 1;
            }
            else {
                if (2*mid + 1 > len_best) {
                    len_best = 2*mid + 1;
                    idx_best = idx;
                }
                left = mid + 1;
            }
        }
        
        return s.substr(idx_best, len_best);
    }
};