class Solution {
public:
    string removeStars(string s) {
        string t = "";
        
        for (char c : s) {
            if (c == '*') {
                if (t != "") {
                    t.pop_back();
                }
            }
            else {
                t.push_back(c);
            }
        }
        
        return t;
    }
};