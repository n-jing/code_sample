#include <iostream>
#include <set>
#include <vector>
#include <array>

using namespace std;




class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> num(n, 1);
    array<int, 3> idx = {0, 0, 0};
    for (int ndx = 1; ndx < n; ++ndx)
    {
      int a = num[idx[0]] * 2;
      int b = num[idx[1]] * 3;
      int c = num[idx[2]] * 5;
      int m = min(a, min(b, c));
      if (m == a)
        ++idx[0];
      if (m == b)
        ++idx[1];
      if (m == c)
        ++idx[2];

      num[ndx] = m;
    }

    return num.back();
  }
};


int main (int argc, char *argv[])
{
  Solution su;
  int p = su.nthUglyNumber(10);
  cerr << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
