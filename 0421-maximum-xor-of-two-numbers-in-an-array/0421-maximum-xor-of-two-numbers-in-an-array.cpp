struct TrieNode {
    TrieNode *children[2];
    
    TrieNode() {
        for (int i = 0; i < 2; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode *root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (curr->children[bit] == nullptr) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    
    int find(int num) {
        TrieNode *curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (curr->children[1 - bit]) {
                curr = curr->children[1 - bit];
                ans |= (1 << i);
            }
            else {
                curr = curr->children[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }
        int ans = 0;
        for (int num : nums) {
            ans = max(ans, trie.find(num));
        }
        return ans;
    }
};