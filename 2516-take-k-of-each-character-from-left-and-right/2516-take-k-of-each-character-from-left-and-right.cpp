const int MN = 1e5 + 10;
int pref[MN][3];

class Solution {
private:
    string s;
    int k;
    
public:
    bool f(int x) {
        const int n = s.size();
        
        for (int i = 1; i <= n - x + 1; ++i) {
            bool flag = true;
            
            for (int j = 0; j < 3; ++j) {
                if (pref[i - 1][j] - pref[0][j] + pref[n][j] - pref[i + x - 1][j] < k) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                return true;
            }
        }
        return false;
    }
    
    int takeCharacters(string s, int k) {
        this->s = s;
        this->k = k;
        const int n = s.size();
        
        memset(pref, 0, sizeof(pref));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                pref[i + 1][j] = pref[i][j] + (s[i] == (j + 'a')); 
            }
        }
        
        int ans = -1;
        int left = 0, right = n;
        
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
        
        if (ans == -1) {
            return ans;
        }
        
        return n - ans;
    }
};