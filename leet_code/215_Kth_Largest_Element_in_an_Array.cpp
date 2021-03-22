#include <queue>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      if (nums.size() < k)
        return 0;
      vector<int> heap(nums.begin(), nums.begin()+k);
      for (int i = k-1; i >= 0; --i)
        HeapSort(heap, i);

      for (int i = k; i < nums.size(); ++i)
      {
        if (nums[i] > heap.front())
        {
          heap[0] = nums[i];
          HeapSort(heap, 0);
        }
      }

      return heap.front();
    }
  void HeapSort(vector<int> &vec, int idx)
    {
      if (idx >= vec.size())
        return ;
      if (2*(idx+1)-1 < vec.size() && vec[idx] > vec[2*(idx+1)-1])
      {
        swap(vec[idx], vec[2*(idx+1)-1]);
        HeapSort(vec, 2*(idx+1)-1);
      }
        
      if (2*(idx+1) < vec.size() && vec[idx] > vec[2*(idx+1)])
      {
        swap(vec[idx], vec[2*(idx+1)]);
        HeapSort(vec, 2*(idx+1));
      } 
    }
};



// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//       priority_queue<int, vector<int>, greater<int>> pq;
//       for (auto n : nums)
//       {
//         if (pq.size() < k)
//         {
//           pq.push(n);
//           continue;
//         }
//         if (pq.top() < n)
//         {
//           pq.pop();
//           pq.push(n);
//         }
//       }
//       return pq.empty() ? 0 : pq.top();
//     }
// };

#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  cerr << "*********************" << endl;
  vector<int> vec = {3,2,3,1,2,4,5,5,6};
  Solution su;
  cerr << su.findKthLargest(vec, 4) << endl;
  
  cerr << "Hello World!" << endl;
  return 0;
}
