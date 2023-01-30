class Solution {
public:
    string maxValue(string n, int x) {
        int size = n.size();
        int j = size;
        if (n[0] == '-') {
            for (int i = size - 1; i >= 1; --i) {
                if (n[i] - '0' > x) {
                    j = i;
                }
            }
        }
        else {
            for (int i = size - 1; i >= 0; --i) {
                if (n[i] - '0' < x) {
                    j = i;
                }
            }
        }
        n.insert(n.begin() + j, x + '0');
        return n;
    }
};