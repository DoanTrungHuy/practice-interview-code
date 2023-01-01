class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string check = word;
        int cnt = 0;
        while (sequence.find(check) != string::npos) {
            cnt += 1;
            check += word;
        }
        return cnt;
    }
};