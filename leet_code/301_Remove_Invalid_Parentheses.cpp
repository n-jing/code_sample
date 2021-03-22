#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <iostream>
#include <stack>


using namespace std;



class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
      const int n = s.size();

      int left_sum = valid_left_brace_num(s);
      string str;
      int left = 0;
      int left_count = 0;
      unordered_set<string> valid_str;
      add_char(0, s, str, left, valid_str, left_count, left_sum);

      vector<string> res;
      for (const string &si : valid_str)
      {
        res.push_back(si);
      }
      if (res.empty())
        res.push_back("");
      return res;
    }

  void add_char(int idx, const string &s, string &str, int &left, unordered_set<string> &valid_str, int left_count, int left_sum)
    {
      if (idx == s.size())
      {
        if (left == 0 && left_count == left_sum)
          valid_str.insert(str);
        return ;
      }

      if (char_valid(s[idx], left))
      {
        if (s[idx] == ')')
        {
          add_char(idx+1, s, str, left, valid_str, left_count, left_sum);
          --left;
          str.push_back(s[idx]);
          add_char(idx+1, s, str, left, valid_str, left_count, left_sum);
          ++left;
          str.pop_back();
        }
        else if (s[idx] == '(')
        {
          add_char(idx+1, s, str, left, valid_str, left_count, left_sum);

          ++left;
          ++left_count;
          str.push_back(s[idx]);
          add_char(idx+1, s, str, left, valid_str, left_count, left_sum);
          --left;
          --left_count;
          str.pop_back();
        }
        else
        {
          str.push_back(s[idx]);
          add_char(idx+1, s, str, left, valid_str, left_count, left_sum);
          str.pop_back();
        }
      }
      else
        add_char(idx+1, s, str, left, valid_str, left_count, left_sum);
    }
  bool char_valid(char c, int left)
    {
      if (left > 0)
        return true;
      if (left == 0 && c == ')')
        return false;
      return true;
    }
  int valid_left_brace_num(const string &s)
    {
      stack<char> sub;
      int valid_num = 0;
      for (auto c : s)
      {
        if (c == '(')
          sub.push(c);
        else if (c == ')' && !sub.empty())
        {
          sub.pop();
          ++valid_num;
        }
      }

      return valid_num;
    }
};

#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  Solution su;
  string str = "x(";
  auto res = su.removeInvalidParentheses(str);
  cerr << res.size() << endl;
  for (auto s : res)
  {
    cerr << s << endl;
  }


  cerr << "Hello World!" << endl;
  return 0;
}
