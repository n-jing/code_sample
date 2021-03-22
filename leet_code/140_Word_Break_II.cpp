#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>


using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      set<char> w_char;
      set<char> s_char;
      for (auto c : s)
        s_char.insert(c);
      for (const auto &w : wordDict)
        for (auto c : w)
          w_char.insert(c);

      for (auto c : s_char)
      {
        if (!w_char.count(c))
          return {};
      }

      if (s.empty())
        return {};
      set<string> wD;
      set<int> w_length;
      for (const string &w : wordDict)
      {
        wD.insert(w);
        w_length.insert(w.size());
      }

      vector<vector<string>> sentences_w(s.size());
      const int N = *(w_length.begin());
      for (int i = N-1; i < s.size(); ++i)
      {
        for (auto l : w_length)
        {
          if (i-l+1 < 0)
            continue;
          string subs = s.substr(i-l+1, l);
          if (wD.count(subs))
          {
            if (i-l < 0)
            {
              sentences_w[i].push_back(subs);
              continue;
            }
            if (sentences_w[i-l].empty())
              continue;
            const int origin_s = sentences_w[i].size();
            copy(sentences_w[i-l].begin(), sentences_w[i-l].end(),
                 back_inserter(sentences_w[i]));
            const int cur_s = sentences_w[i].size();
            for (int si = origin_s; si < cur_s; ++si)
              sentences_w[i][si] += " " + subs;
          }
        }
      }

      return sentences_w.back();
    }
};

#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  string s = "pineapplepenapple";
  vector<string> vec = {"apple", "pen", "applepen", "pine", "pineapple"};
  Solution su;
  auto res = su.wordBreak(s, vec);
  cerr << "RRRRRRRRRRRRRRRRRRRRRRRR" << endl;
  cerr << res.size() << endl;
  for (auto s : res)
  {
    cerr << s << endl;
  }

  return 0;
}
