class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n = a.size(), m = b.size();
        int i = n - 1, j = m - 1;  
        string ans = "";
        while (i >= 0 || j >= 0 || carry) {
            int temp = carry;
            if (i >= 0) {
                temp += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                temp += b[j] - '0';
                j--;
            }
            carry = temp / 2;
            ans.push_back(temp % 2 + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};