#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
      counter_.insert(num);
      int n = counter_.size();
      if (n == 1)
      {
        hi_median_ = lo_median_ = counter_.begin();
      }
      else if ( n % 2 == 0)
      {
        if (num >= *hi_median_)
        {
          hi_median_++;
        }
        else
        {
          lo_median_--;
        }
      }
      else
      {
        if (num >= *lo_median_ && num < *hi_median_)
        {
          lo_median_++;
          hi_median_--;
        }
        else if (num >= *hi_median_)
        {
          lo_median_++;
        }
        else
        {
          hi_median_--;
        }
      }
    }
    
    double findMedian() {
      return (*lo_median_ + *hi_median_) / 2.0;
    }
  multiset<int> counter_;
  multiset<int>::iterator lo_median_;
  multiset<int>::iterator hi_median_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main (int argc, char *argv[])
{
  MedianFinder me;

  
  return 0;
}
