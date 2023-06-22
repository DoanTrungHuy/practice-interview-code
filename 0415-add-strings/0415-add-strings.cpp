class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int i = n - 1, j = m - 1;
        int carry = 0;
        string ans;
        
        while (i >= 0 or j >= 0 or carry) {
            int sum = 0;
            if (i >= 0) {
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }
            sum += carry;
            ans.push_back(sum%10 + '0');
            carry = sum / 10;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};