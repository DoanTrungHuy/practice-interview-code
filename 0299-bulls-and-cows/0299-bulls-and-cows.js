class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int cntSec[10] = {}, cntGue[10] = {};
        int bulls = 0, cows = 0;
        
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                cntSec[secret[i] - '0']++;
                cntGue[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            cows += min(cntSec[i], cntGue[i]);
        }
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};