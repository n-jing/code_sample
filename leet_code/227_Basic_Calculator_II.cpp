#include <vector>
#include <iostream>
#include <string>


using namespace std;





class Solution {
public:
    int calculate(string s) {
      if (s.empty())
        return 0;
      const int N = s.size();
      string expression(1, '0');
      for (int i = 0; i < N; ++i)
      {
        if (s[i] != ' ')
          expression += s[i];
      }
      vector<string> split_by_plus = split_string(expression, '+');
      vector<vector<string>> split_by_minus;
      for (const string &str : split_by_plus)
      {
        vector<string> item = split_string(str, '-');
        split_by_minus.push_back(move(item));
      }

      int sum = 0;
      for (const auto &item : split_by_minus)
      {
        sum += evaluate_mul_and_div(item[0]);
        for (int i = 1; i < item.size(); ++i)
        {
          sum -= evaluate_mul_and_div(item[i]);
        }
      }

      return sum;
    }

  int evaluate_mul_and_div(const string &str)
    {
      vector<string> exp_mul = split_string(str, '*');
      int base = 1;
      for (const auto &e : exp_mul)
      {
        vector<string> exp_div = split_string(e, '/');
        vector<int> exp_num = convert_to_int(exp_div);
        base *= exp_num[0];
        for (int i = 1; i < exp_num.size(); ++i)
        {
          base /= exp_num[i];
        }
      }
      return base;
    }
  vector<string> split_string(const string &str, char p)
    {
      vector<string> vec;
      for (int i = 0; i < str.size();)
      {
        int next = str.find(p, i);
        string sub = str.substr(i, next - i);
        vec.push_back(move(sub));
        if (next == string::npos)
          break;
        i = next + 1;
      }
      return vec;
    }
  vector<int> convert_to_int(const vector<string> &vec)
    {
      vector<int> exp(vec.size());
      for (int i = 0; i < vec.size(); ++i)
      {
        exp[i] = stoi(vec[i]);
      }
      return exp;
    }
};

int main (int argc, char *argv[])
{
  string s = "-13/42";
  Solution su;
  int c = su.calculate(s);
  cerr << "eval:" << c << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
