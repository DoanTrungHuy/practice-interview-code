class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;
        map<vector<int>, bool> um1;
        map<vector<int>, bool> um2;
        for (auto it1 : items1) {
            for (auto it2 : items2) {
                if (it1[0] == it2[0]) {
                    res.push_back({it1[0], it2[1] + it1[1]});
                    um1[it1] = true;
                    um2[it2] = true;
                }
            }
        }
        for (auto it1 : items1) {
            if (um1.find(it1) == um1.end()) {
                res.push_back(it1);
            }
        }
        for (auto it2 : items2) {
            if (um2.find(it2) == um2.end()) {
                res.push_back(it2);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};