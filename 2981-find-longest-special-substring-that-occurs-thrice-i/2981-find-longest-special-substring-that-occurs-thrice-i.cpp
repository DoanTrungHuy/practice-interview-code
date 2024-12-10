using ll = long long;

class RollingHash {
private:
    string s;
    int sz;
    vector<ll> h, p;
    
public:
    const static ll BASE = 7;
    const static ll MOD = 1e9 + 7;
    
    RollingHash() {
        
    }
    
    RollingHash(string s) {
        this->s = s;
        sz = s.size();
        h.resize(sz + 1);
        p.resize(sz + 1);
        p[0] = 1;
        for (int i = 1; i <= sz; ++i) {
            h[i] = (h[i - 1]*BASE + s[i - 1] - 'a') % MOD;
            p[i] = (p[i - 1]*BASE) % MOD;
        }
    }
    
    int subval(int l, int r) {
        l++;
        r++;
        return (h[r] - (h[l - 1]*p[r - l + 1]) % MOD + MOD*MOD) % MOD;
    }
};

class Solution {
private:
    string s;
    RollingHash *rh;
    
public:
    bool f(int k) {
        const int n = s.size();
        unordered_map<int, int> freq, cnt_val;
        
        for (int i = 0; i < k; ++i) {
            cnt_val[s[i]]++;
        }
        
        if (cnt_val.size() == 1) {
            ++freq[rh->subval(0, k - 1)];
        }
        
        for (int i = k; i < n; ++i) {
            cnt_val[s[i]]++;
            cnt_val[s[i - k]]--;
            
            if (cnt_val[s[i - k]] == 0) {
                cnt_val.erase(s[i - k]);
            }
            
            if (cnt_val.size() == 1 && ++freq[rh->subval(i - k + 1, i)] == 3) {
                return true;
            }
        }
        
        return false;
    }
    
    int maximumLength(string s) {
        this->s = s;
        const int n = s.size();
        int ans = -1;
        int left = 1, right = n;
        
        rh = new RollingHash(s);
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (f(mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};