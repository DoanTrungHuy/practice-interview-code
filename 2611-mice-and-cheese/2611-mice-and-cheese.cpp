class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward2.size();
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; ++i) {
            v.push_back({reward2[i] - reward1[i], i});
        }
        
        sort(v.begin(), v.end());
        
        int ans = 0, i = 0;
        
        while(k--)
        {
            ans += reward1[v[i].second];
            i++;
        }

        while(i < n)
        {
            ans += reward2[v[i].second];
            i++;
        }
        
        return ans;
    }
};