#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;



class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
      int a = min(x, y);
      int b = max(x, y);
      if (a == 0)
      {
        if (b == z || z == 0)
          return true;
        else
          return false;
      }
      int r = gcd(a, b);
      return (z%r == 0) && z <= b+a;
    }
};


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  Solution su;
  int p = su.canMeasureWater(1, 2, 3);
  cerr << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
