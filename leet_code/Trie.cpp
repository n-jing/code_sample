#include <string>
#include <algorithm>

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
      is_end_ = false;
      std::fill(next_, next_+26, nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
      Trie *t = this;
      for (auto c : word)
      {
        if (t->next_[c-'a'] == nullptr)
          t->next_[c-'a'] = new Trie();
        t = t->next_[c-'a'];
      }
      t->is_end_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
      Trie *t = this;
      for (auto c : word)
      {
        if (t->next_[c-'a'] == nullptr)
          return false;
        t = t->next_[c-'a'];
      }
      return t->is_end_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
      Trie *t = this;
      for (auto c : prefix)
      {
        if (t->next_[c-'a'] == nullptr)
          return false;
        t = t->next_[c-'a'];
      }
      return true;
    }
private:
  bool is_end_;
  Trie *next_[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
