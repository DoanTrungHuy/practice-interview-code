class Solution {
public:
    string decodeAtIndex(string s, int k) {
        const int n = s.size();
        long long real_size = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                real_size = real_size * (c - '0');
            }
            else {
                real_size++;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            k %= real_size;
            
            if (isdigit(c)) {
                real_size /= (c - '0');
            }
            else {
                if (k == 0) {
                    return string(1, c);
                }
                real_size--;
            }
        }
        
        return "";
    }
};