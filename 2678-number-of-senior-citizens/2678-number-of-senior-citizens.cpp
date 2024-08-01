class Solution {
public:
    int countSeniors(vector<string>& details) {
        const int n = details.size();
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            cout << details[i][11] << details[i][12] << '\n';
            int num = (details[i][11] - '0')*10 + (details[i][12] - '0');
            if (num > 60) {
                cnt++;
            }
        }
        
        return cnt;
    }
};