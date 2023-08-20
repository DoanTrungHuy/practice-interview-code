class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if(m > n) {
            return false;
        }
        
        int j = 0;
        
        for(int i = 0; i < n and j < m; i++){
            if(s1[i] == s2[j]) {
                j++;
            } else if((((s1[i] - 'a') + 1)%26 + 'a') == s2[j]) {
                j++;
            }
        }
        
        return j == m;
    }
};