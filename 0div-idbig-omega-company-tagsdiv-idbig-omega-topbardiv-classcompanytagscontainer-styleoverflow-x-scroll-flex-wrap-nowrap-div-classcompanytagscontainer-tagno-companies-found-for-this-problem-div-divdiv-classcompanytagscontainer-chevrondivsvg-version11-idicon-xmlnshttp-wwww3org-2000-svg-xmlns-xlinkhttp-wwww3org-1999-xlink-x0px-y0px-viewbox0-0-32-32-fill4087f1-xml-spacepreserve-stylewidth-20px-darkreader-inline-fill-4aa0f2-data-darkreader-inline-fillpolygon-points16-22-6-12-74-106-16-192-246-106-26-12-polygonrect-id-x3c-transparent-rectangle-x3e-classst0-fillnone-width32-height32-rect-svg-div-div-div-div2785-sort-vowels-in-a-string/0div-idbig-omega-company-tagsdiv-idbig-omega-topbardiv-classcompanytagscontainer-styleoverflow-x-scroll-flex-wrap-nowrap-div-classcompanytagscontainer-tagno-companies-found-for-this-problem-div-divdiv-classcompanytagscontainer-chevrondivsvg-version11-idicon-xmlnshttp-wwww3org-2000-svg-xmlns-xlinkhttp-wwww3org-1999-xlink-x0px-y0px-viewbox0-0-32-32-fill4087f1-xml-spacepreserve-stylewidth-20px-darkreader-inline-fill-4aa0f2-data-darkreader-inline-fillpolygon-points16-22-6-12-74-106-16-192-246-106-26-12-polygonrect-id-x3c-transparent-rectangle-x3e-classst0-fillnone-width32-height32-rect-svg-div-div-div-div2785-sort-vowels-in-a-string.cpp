class Solution {
public:
    string sortVowels(string s) {
        const int n = s.size();
        vector<bool> visited(n, false);
        
        string t = "UEOAIueoai";
        string c = "";
        
        for (int i = 0; i < n; ++i) {
            if (t.find(s[i]) != string::npos) {
                visited[i] = true;
                c.push_back(s[i]);
            }
        }
        
        sort(c.begin(), c.end());
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                s[i] = c[j];
                j++;
            }
        }
        
        return s;
    }
};