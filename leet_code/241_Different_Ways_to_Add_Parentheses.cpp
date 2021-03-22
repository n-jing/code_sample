#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>


using namespace std;



class Solution {
  enum OP
  {
    ADD,
    MINUS,
    MULTI
  };
public:
    vector<int> diffWaysToCompute(string input) {
      if (input.empty())
        return {};
      int idx = 0;
      vector<OP> operat;
      vector<int> number;
      if (!(input[0] >= '0' && input[0] <= '9'))
        input = "0" + input;
      
      while (idx < input.size())
      {
        int n = 0;
        while (idx < input.size() && input[idx] >= '0' && input[idx] <= '9')
        {
          n = n*10 + input[idx] - '0';
          ++idx;
        }
        number.push_back(n);
        if (input[idx] == '+')
          operat.push_back(ADD);
        else if (input[idx] == '-')
          operat.push_back(MINUS);
        else if (input[idx] == '*')
          operat.push_back(MULTI);
        ++idx;
      }
      cerr << number.size() << " " << operat.size() << endl;
      cerr << input << endl;
      cerr << "*******************" << endl;
      vector<int> res;
      vector<bool> choosed(operat.size(), false);
      CalculatePossibleResults(choosed, operat, number, res);
      return res;
    }

  void CalculatePossibleResults(vector<bool> &choosed, vector<OP> &operat, vector<int> &number, vector<int> &res)
    {
      for (auto t : choosed)
      {
        cerr << t << " ";
      }
      cerr << endl;
      for (auto n : number)
      {
        cerr << n << " ";
      }
      cerr << endl;
      getchar();
      const int N = choosed.size();
      for (int i = 0; i < N; ++i)
      {
        if (choosed[i] == true)
          continue;
        choosed[i] = true;
        int r = 0;
        switch (operat[i])
        {
        case ADD:
          r = number[i] + number[i+1];
          break;
        case MINUS:
          r = number[i] - number[i+1];
          break;
        default:
          r = number[i] * number[i+1];
        }
        if (find(choosed.begin(), choosed.end(), false) == choosed.end())
        {
          res.push_back(r);
          choosed[i] = false;
          return ;
        }
        int ni = number[i];
        int nj = number[i+1];
        number[i] = number[i+1] = r;
        CalculatePossibleResults(choosed, operat, number, res);
        choosed[i] = false;
        number[i] = ni;
        number[i+1] = nj;
      }

    }
};


int main (int argc, char *argv[])
{
  Solution su;
  string str = "2*3-4*5";
  vector<int> res = su.diffWaysToCompute(str);
  for (auto r : res)
  {
    cerr << r << " ";
  }
  cerr << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
