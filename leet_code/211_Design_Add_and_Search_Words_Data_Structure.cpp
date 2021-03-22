#include <iostream>
#include <vector>
#include <string>



using namespace std;


class Tries
{
public:
  Tries()
    {
      fill(next_char, next_char+26, nullptr);
      end = false;
    }
  ~Tries()
    {
      for (int i = 0; i < 26; ++i)
      {
        if (next_char[i])
          delete[] next_char[i];
      }
    }

  Tries *next_char[26];
  bool end;
};



class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
      
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
      Tries *t = &dic;
      const int N = word.size();
      int idx = 0;
      while (idx < N)
      {
        if (t->next_char[word[idx]-'a'] == nullptr)
          t->next_char[word[idx]-'a'] = new Tries();
        t = t->next_char[word[idx]-'a'];
        ++idx;
      }
      t->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      return SearchCharacter(word, 0, &dic);
    }
  bool SearchCharacter(const string &word, int idx, Tries *t)
    {
      if (t == nullptr)
        return false;
      // for (int i = 0; i < 26; ++i)
      // {
      //   cerr << t->next_char[i] << endl;
      // }
      // getchar();
      
      if (idx == word.size())
      {
        if (t->end)
          return true;
        else
          return false;
      }
      
      if (word[idx] != '.')
      {
        if (t->next_char[word[idx]-'a'] == nullptr)
          return false;
        else
          return SearchCharacter(word, idx+1, t->next_char[word[idx]-'a']);
      }
      else
      {
        for (int i = 0; i < 26; ++i)
        {
          if (t->next_char[i])
          {
            bool exist = SearchCharacter(word, idx+1, t->next_char[i]);
            if (exist)
              return exist;
          }
        }
        return false;
      }
      return false;
    }
  
  Tries dic;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main (int argc, char *argv[])
{
  WordDictionary wordDictionary;
  wordDictionary.addWord("bad");
  wordDictionary.addWord("dad");
  wordDictionary.addWord("mad");
  wordDictionary.search("pad"); // return False
  wordDictionary.search("bad"); // return True
  wordDictionary.search(".ad"); // return True
  wordDictionary.search("b.."); // return True
  return 0;
}
