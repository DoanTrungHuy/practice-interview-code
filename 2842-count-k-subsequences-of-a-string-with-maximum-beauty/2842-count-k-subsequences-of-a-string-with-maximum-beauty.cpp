class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        const long long mod = 1000000007LL;
        vector <vector <long long> > C; 
        C.resize(27);
        for (int i = 0; i <= 26; i++) {
            C[i].resize(27, 0LL); 
        }
        for (int i = 0; i <= 26; i++) {
            C[i][i] = 1;
            C[i][0] = 1;
        }
        for (int i = 1; i <= 26; i++) {
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod; 
            }
        }
        vector <int> cnt;
        cnt.clear();
        cnt.resize(26, 0); 
        for (int i = 0; i < (int) s.size(); i++) {
            cnt[s[i] - 'a']++; 
        }
        sort(cnt.begin(), cnt.end()); 
        long long ans = 1LL; 
        for (int i = 25; i >= 0; i--) {
            if (k > 0) {
                (ans *= (long long) cnt[i]) %= mod; 
                k--; 
                if (k == 0) {    
                    int cntEqual = 0;
                    int p = -1; 
                    for (int j = i; j <= 25; j++) {
                        if (cnt[j] == cnt[i]) {
                            cntEqual++; 
                            p = j; 
                        }
                    }
                    for (int j = i - 1; j >= 0; j--) {
                        if (cnt[j] == cnt[i]) {
                            cntEqual++; 
                        }
                    }
                    (ans *= C[cntEqual][p - i + 1]) %= mod;
                }
            }
            else { 
                break; 
            }
        }
        return (int) ans; 
    }
};