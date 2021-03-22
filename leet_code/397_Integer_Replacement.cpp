#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
      vector<int> num(n, 0);
      for (int i = 1; i < n; ++i)
      {
        if (i % 2 == 1)
          num[i] = num[(i-1)/2] + 1;
        else
        {
          int a = num[i]+1;
          int b = num[(i+2)/2-1] + 2;
          num[i-1] = min(a, b);
        }
      }
      return num.back();
    }
};


int main (int argc, char *argv[])
{
  Solution su;
  cerr << su.integerReplacement(7) << endl;
  cerr << su.integerReplacement(15) << endl;
  cerr << su.integerReplacement(10) << endl;

  cerr << "Hello World!" << endl;
  return 0;
}
