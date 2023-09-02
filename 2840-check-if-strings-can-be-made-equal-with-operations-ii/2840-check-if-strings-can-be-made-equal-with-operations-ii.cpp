class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string t1, t2;
        for (int i = 0; i < s1.size(); i += 2) {
            t1 += s1[i];
            t2 += s2[i];
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) {
            return false;
        }
        t1 = t2 = "";
        for (int i = 1; i < s1.size(); i += 2) {
            t1 += s1[i];
            t2 += s2[i];
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) {
            return false;
        }
        return true;
    }
};