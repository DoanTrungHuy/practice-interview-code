class Solution {
public:
    int maximum69Number (int num) {
        string digit = to_string(num);
        for (int i = 0; i < digit.size(); ++i) {
            if (digit[i] == '6') {
                digit[i] = '9';
                break;
            }
        }
        return stoi(digit);
    }
};