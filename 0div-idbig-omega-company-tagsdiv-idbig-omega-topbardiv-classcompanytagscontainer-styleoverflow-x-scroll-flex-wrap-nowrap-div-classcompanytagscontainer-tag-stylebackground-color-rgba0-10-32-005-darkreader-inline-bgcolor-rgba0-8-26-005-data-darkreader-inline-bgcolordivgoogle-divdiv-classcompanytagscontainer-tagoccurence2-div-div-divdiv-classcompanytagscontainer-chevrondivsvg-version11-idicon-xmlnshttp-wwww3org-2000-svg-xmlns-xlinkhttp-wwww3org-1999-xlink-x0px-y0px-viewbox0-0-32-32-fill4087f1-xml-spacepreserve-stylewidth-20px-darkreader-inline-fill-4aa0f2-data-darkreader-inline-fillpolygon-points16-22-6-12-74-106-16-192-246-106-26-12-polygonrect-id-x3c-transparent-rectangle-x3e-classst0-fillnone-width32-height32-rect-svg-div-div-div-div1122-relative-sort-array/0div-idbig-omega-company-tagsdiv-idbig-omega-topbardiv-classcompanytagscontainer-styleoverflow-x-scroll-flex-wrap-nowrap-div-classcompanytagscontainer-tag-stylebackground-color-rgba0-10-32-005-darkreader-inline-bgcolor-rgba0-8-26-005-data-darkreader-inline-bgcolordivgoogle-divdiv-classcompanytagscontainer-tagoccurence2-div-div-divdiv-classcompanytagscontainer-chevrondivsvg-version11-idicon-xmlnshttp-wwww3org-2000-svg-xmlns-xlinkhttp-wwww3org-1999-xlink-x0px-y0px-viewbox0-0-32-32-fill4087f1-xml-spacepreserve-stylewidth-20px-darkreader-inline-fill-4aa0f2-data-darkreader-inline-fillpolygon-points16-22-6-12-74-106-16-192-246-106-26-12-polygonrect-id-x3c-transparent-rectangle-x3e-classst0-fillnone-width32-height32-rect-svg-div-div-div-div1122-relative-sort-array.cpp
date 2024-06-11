class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mm;
        const int n = arr1.size();
        for (int i = 0; i < n; ++i) {
            mm[arr1[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < arr2.size(); ++i) {
            while (mm[arr2[i]]--) {
                ans.push_back(arr2[i]);
            }
            mm.erase(arr2[i]);
        }
        for (auto [key, val] : mm) {
            while (val--) {
                ans.push_back(key);
            }
        }
        return ans;
    }
};