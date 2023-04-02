class Solution {
public:
    int search(vector<int>& arr, long long target) {
      int left = 0, right = arr.size();
      while(left < right) {
        int middle = left + (right - left) / 2;
        if(arr[middle] < target) {
          left = middle + 1;
        } else {
          right = middle;
        }
      }
      return (int)arr.size() - right;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans = {};
        int n = potions.size();
        for(int spell: spells) {
          ans.push_back(search(potions, (long long)ceil(success * 1.0 / spell)));
        }
        return ans;
    }
};