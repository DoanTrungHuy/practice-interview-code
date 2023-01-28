class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag = false;
        for (string word : wordList) {
            if (word == endWord) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            return 0;
        }
        queue<string> mq;
        int step = 0;
        mq.push(beginWord);
        unordered_set<string> us(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!mq.empty()) {
            int n = mq.size();
            while (n--) {
                string word = mq.front();
                mq.pop();
                if (word == endWord) {
                    return step + 1;
                }
                int m = word.size();
                for (int i = 0; i < m; ++i) {
                    char tmp = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (tmp == c) {
                            continue;
                        }
                        word[i] = c;
                        if (visited.find(word) == visited.end() and us.find(word) != us.end()) {
                            mq.push(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = tmp;
                }
            }
            step += 1;
        }
        return 0;
    }
};