#include <vector>
#include <iostream>
#include <random>


using namespace std;


int main (int argc, char *argv[])
{
  default_random_engine e;
  uniform_real_distribution<double> u(0, 2);
  long long count = 0;
  long long N = 1e6;
  cout << count << " " << N << endl;
  for (long long i = 0; i < N; ++i)
  {
    double a = u(e);
    double b = u(e);
    double c = u(e);
    if (a < 1 && b < 1 && c < 1)
      count++;
    else if  (a > 1 && b > 1 && c > 1)
      count++;
  }

  cout << double(count) / double(N) << endl;
  return 0;
}
