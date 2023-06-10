class Solution {
public:
    bool isFascinating(int n) {
        string num = to_string(n) + to_string(2*n) + to_string(3*n);
        sort(num.begin(), num.end());
        return num == "123456789";
    }
};