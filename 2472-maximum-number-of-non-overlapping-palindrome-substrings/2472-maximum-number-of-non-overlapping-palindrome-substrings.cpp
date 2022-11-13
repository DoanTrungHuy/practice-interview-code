class Solution {
private:
    int n, k;
    
public:
    int helper(string &s, int l, int r) {
        int cnt = 0;
        while (0 <= l and r < n and s[l] == s[r] and isalpha(s[l]) and isalpha(s[r])) {
            if (r - l + 1 >= k) {
                cnt++;
                s[l] = '$';
                s[r] = '$';
                break;
            }
            l--;
            r++;
        }
        return cnt;
    }
    int maxPalindromes(string s, int k) {
        this->n = s.size();
        this->k = k;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += helper(s, i, i) + helper(s, i, i + 1);
        }
        return res;
    }
};