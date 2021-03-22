#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> number;
      const int tokens_num = tokens.size();
      int res = 0;
      for (int i = 0; i < tokens_num; ++i)
      {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
          int a = number.top();
          number.pop();
          int b = number.top();
          number.pop();
          if (tokens[i] == "+")
            number.push(b+a);
          else if (tokens[i] == "-")
            number.push(b-a);
          else if (tokens[i] == "/")
            number.push(b/a);
          else
            number.push(b*a);
        }
        else
        {
          cerr << stoi(tokens[i]) << " ";
          number.push(stoi(tokens[i]));
        }
          
      }

      return number.top();
    }
};


int main (int argc, char *argv[])
{
  vector<string> vec = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  Solution su;
  int r = su.evalRPN(vec);
  cerr << r << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
