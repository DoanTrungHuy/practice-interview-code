struct TrieNode {
    bool is_word;
    TrieNode *child[26];
    
    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
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
    
    void insert(string word) {
        TrieNode *curr = root;
        
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode();
            }
            curr = curr->child[c - 'a'];
        }
        
        curr->is_word = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->child[c - 'a'];
        }
        
        return curr->is_word;
    }
    
    bool startsWith(string word) {
        TrieNode *curr = root;
        
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->child[c - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */