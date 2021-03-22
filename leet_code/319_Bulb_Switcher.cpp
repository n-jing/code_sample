#include <vector>
#include <iostream>


using namespace std;



class Solution {
public:
    int bulbSwitch(int n) {
      vector<bool> light(n, false);
      for (int i = 0; i < n; ++i)
      {
        for (int j = i; j < n; j += i+1)
        {
          light[j] = !light[j];
        }
      }

      int count = 0;
      for (int i = 0; i < n; ++i)
      {
        count += light[i];
      }

      return count;
    }
};

int main (int argc, char *argv[])
{
  Solution su;
  int p = su.bulbSwitch(2);
  cerr << p << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
