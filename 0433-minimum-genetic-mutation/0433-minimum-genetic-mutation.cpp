class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> mq;
        mq.push(start);
        unordered_map<string, bool> visited;
        int step = 0;
        while (!mq.empty()) {
            int n = mq.size();
            while (n--) {
                string word = mq.front();
                mq.pop();
                if (word == end) {
                    return step;
                }
                for (int i = 0; i < 8; ++i) {
                    char tmp = word[i];
                    for (int j = 0; j < 4; ++j) {
                        word[i] = "ACGT"[j];
                        if (!visited[word] and find(bank.begin(), bank.end(), word) != bank.end()) {
                            mq.push(word);
                            visited[word] = true;
                        }
                    }
                    word[i] = tmp;
                }
            }
            step++;
        }
        return -1;
    }
};