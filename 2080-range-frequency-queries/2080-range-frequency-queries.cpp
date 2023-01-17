class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> um;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < (int)arr.size(); ++i) {
            um[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int> &v = um[value];
        int idx1 = upper_bound(v.begin(), v.end(), right) - v.begin();
        int idx2 = lower_bound(v.begin(), v.end(), left) - v.begin();
        return idx1 - idx2;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */