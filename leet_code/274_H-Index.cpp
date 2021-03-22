#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end(), greater<int>());
      int idx = 0;
      const int N = citations.size();
      for (idx; idx < N; ++idx)
      {
        if (citations[idx] < idx+1)
          break;
      }

      return idx;
    }
};


int main (int argc, char *argv[])
{

  cerr << "Hello World!" << endl;
  return 0;
}
