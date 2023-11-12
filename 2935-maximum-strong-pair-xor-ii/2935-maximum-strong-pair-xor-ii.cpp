class TrieNode {
public:
    TrieNode *child[2] = {nullptr, nullptr};
    int cnt = 0;
};

class Trie {
private:
    TrieNode *root = new TrieNode();

public:
    void insert(int num) {
        TrieNode *current = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (current->child[bit] == nullptr) {
                current->child[bit] = new TrieNode();
            }
            current = current->child[bit];
            current->cnt++;
        }
    }

    int find(int num) {
        TrieNode *current = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (current->child[1 - bit] and current->child[1 - bit]->cnt > 0) {
                ans |= (1 << i);
                current = current->child[1 - bit];
            } else {
                current = current->child[bit];
            }
        }
        return ans;
    }

    void _delete(int num) {
        TrieNode *current = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (current->child[bit]) {
                current = current->child[bit];
                current->cnt--;
            }
            else {
                break;
            }
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie trie;
        const int n = nums.size();
        int ans = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            trie.insert(nums[i]);
            while (2 * nums[j] < nums[i]) {
                trie._delete(nums[j]);
                j++;
            }
            ans = max(ans, trie.find(nums[i]));
        }
        return ans;
    }
};