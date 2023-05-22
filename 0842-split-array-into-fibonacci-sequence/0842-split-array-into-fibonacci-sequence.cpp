using ll = long long;
const ll LIMIT = 1 << 31;

class Solution {
private:
    vector<int> path;
    int n;
    
public:
    bool dfs(string &num, int i, ll f1, ll f2, int size) {
        if (i == n) {
            return size > 2;
        }
        ll totalDEC = 0;
        for (int j = i; j < n; ++j) {
            totalDEC = 10*totalDEC + (num[j] - '0') * 1LL;
            if (num[i] == '0' and j > i) {
                break;
            }
            if ((ll)INT_MAX < totalDEC) {
                break;
            }
            if (size < 2 or f1 + f2 == totalDEC) {
                path.push_back(totalDEC);
                if (dfs(num, j + 1, f2, totalDEC, size + 1)) {
                    return true;
                }
                path.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        n = num.size();
        dfs(num, 0, 0LL, 0LL, 0LL);
        return path;
    }
};