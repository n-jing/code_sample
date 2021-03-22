#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main (int argc, char *argv[])
{
  map<int, int> mp;
  cerr << mp.size() << " " << mp[0] << " " << mp.size() << " " << mp[1] << " " << mp.size() << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
