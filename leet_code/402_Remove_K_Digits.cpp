#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

void ElementSort(vector<int> &vec, int l, int r)
{
  if (l >= r)
    return ;
  int a = l;
  int b = r;
  while (a < b)
  {
    while (a < b && vec[b] >= vec[l])
      --b;
    while (a < b && vec[a] < vec[l])
      ++a;
    swap(vec[a], vec[b]);
  }
  swap(vec[l], vec[b]);

  ElementSort(vec, l, b-1);
  ElementSort(vec, b+1, r);
}


void QuickSort(vector<int> &vec)
{
  ElementSort(vec, 0, vec.size()-1);
}

void MaoSort(vector<int> &vec)
{
  const int N = vec.size();
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N-1-i; ++j)
    {
      if (vec[j] > vec[j+1])
        swap(vec[j], vec[j+1]);
    }
  }
  
}

int main (int argc, char *argv[])
{
  vector<int> vec = {1, 3, 4, 5, 2, 3, 19, -1, -3, 3};
  MaoSort(vec);
  for (auto e : vec)
  {
    cerr << e << " ";
  }
  cerr << endl; 
  return 0;
}
