#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    int integerBreak(int n) {
      if (n <= 3)
        return n-1;
      int p = n / 3;
      int q = n % 3;
      if (q == 0)
      {
        return pow(3, p);
      }
      else if (q == 1)
      {
        return pow(3, p-1) * 4;
      }
      else
      {
        return pow(3, p-1) * 6;
      }

      return 0;
    }
};


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  Solution su;
  for (int i = 2; i < 12; ++i)
  {
    cerr << su.integerBreak(i) << " ";

  }
  cerr << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
