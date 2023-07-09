using ll = unsigned long long;

class Solution {
private:
    vector<ll> h, p;
    string s;
    
public:
    const ll base = 131;
    const ll mod = 1;
    
    string get_str(int k) {
        unordered_set<ll> flag;
        int n = s.size();
        
        for (int i = 1; i <= n - k + 1; ++i) {
            int l = i;
            int r = i + k - 1;
            ll get_hash = h[r] - h[l - 1]*p[r - l + 1];
            if (flag.count(get_hash)) {
                return s.substr(l, r - l + 1);
            }
            flag.insert(get_hash);
        }
        
        return "";
    }
    
    string longestDupSubstring(string s) {
        s = " " + s;
        this->s = s;
        int n = s.size();
        h.resize(n + 1, 0);
        p.resize(n + 1, 1);
        
        for (int i = 1; i < n; ++i) {
            h[i] = h[i - 1]*base + s[i] - 'a';
            p[i] = p[i - 1]*base;
        }
        
        int left = 1, right = n - 1;
        string ans = "";
        
        while (left <= right) {
            int mid = (left + right) / 2;
            string str_valid = get_str(mid);
            if (str_valid.size()) {
                ans = str_valid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};