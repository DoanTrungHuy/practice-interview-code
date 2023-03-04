class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        
        unordered_map<int, int> um;
        
        int rank = 0;
        
        for (int num : s) {
            um[num] = ++rank;
        }
        
        vector<int> ans;
        
        for (int num : arr) {
            ans.push_back(um[num]);
        }
        
        return ans;
    }
};