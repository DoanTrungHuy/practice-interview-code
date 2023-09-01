class MajorityChecker {
private:
    vector<int> arr;
    map<int, vector<int>> idx;
    
public:
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        for (int i = 0; i < (int)arr.size(); ++i) {
            idx[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (int pick = 0; pick < 10; ++pick) {
            int random_ = arr[left + rand() % (right - left + 1)];
            const vector<int> &tmp = idx[random_];
            auto br = upper_bound(tmp.begin(), tmp.end(), right);
            auto bl = lower_bound(tmp.begin(), tmp.end(), left);
            
            if (br - bl >= threshold) {
                return random_;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */