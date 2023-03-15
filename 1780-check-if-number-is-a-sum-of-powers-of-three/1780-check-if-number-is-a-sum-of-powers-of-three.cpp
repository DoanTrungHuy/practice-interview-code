class Solution {
private:
    bool flag;
public:
    void backTracking(int i, int s) {
        if (flag || s < 0) {
            return;
        }
        if (s == 0) {
            flag = true;
            return;
        }
        for (int j = i; j < 16; ++j) {
            backTracking(j + 1, s - pow(3, j));
        }
    }
    bool checkPowersOfThree(int n) {
        flag = false;
        backTracking(0, n);
        return flag;
    }
};