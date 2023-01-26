class Solution {
private:
    vector<string> ans;
    int n;
    vector<string> letters;
    string digits;
    
public:
    void backTracking(int i, string path) {
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }
        for (char c : letters[digits[i] - '0' - 2]) {
            backTracking(i + 1, path + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        this-> n = digits.size();
        if (n == 0) {
            return {};
        }
        int step = 3;
        char chr = 'a';
        for (int i = 2; i <= 9; ++i) {
            if (i == 7 or i == 9) {
                step = 4;
            }
            else {
                step = 3;
            }
            string letter;
            for (int j = 0; j < step; ++j) {
                letter += chr;
                chr += 1;
            }
            letters.push_back(letter);
        }
        this->digits = digits;
        backTracking(0, "");
        return ans;
    }
};