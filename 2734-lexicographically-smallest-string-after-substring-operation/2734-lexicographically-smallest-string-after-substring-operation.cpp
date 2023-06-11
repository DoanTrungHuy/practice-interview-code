class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0;
        
        while (i < n and s[i] == 'a') {
            i++;
        }
        
        bool check = false;
        
        for (int j = i; j < n and s[j] != 'a'; ++j) {
            s[j]--;
            check = true;
        }
        
        if (check == false) {
            s[n - 1] = 'z';
        }
        
        return s;
    }
};