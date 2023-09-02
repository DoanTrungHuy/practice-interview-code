class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t1, t2;
        
        t1 += s1[0];
        t1 += s1[2];
        t2 += s2[0];
        t2 += s2[2];
        
        if (t1 != t2) {
            swap(t1[0], t1[1]);
            if (t1 != t2) {
                return false;
            }
        }
        
        t1 = t2 = "";
        
        t1 += s1[1];
        t1 += s1[3];
        t2 += s2[1];
        t2 += s2[3];
        
        if (t1 != t2) {
            swap(t1[0], t1[1]);
            if (t1 != t2) {
                return false;
            }
        }
        
        return true;
    }
};