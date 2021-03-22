#include <vector>
#include <iostream>
#include <array>
#include <cmath>


using namespace std;




class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    if (points.size() <= 2)
      return points.size();
    const int point_num = points.size();
    vector<array<int, 5>> all_segment;
    for (int i = 0; i < point_num; ++i)
    {
      for (int j = i+1; j < point_num; ++j)
      {
        array<int, 5> seg = {points[i][0], points[i][1], points[j][0], points[j][1], 0};
        all_segment.push_back(seg);
      }
    }

    const int seg_num = all_segment.size();
    for (int i = 0; i < seg_num; ++i)
    {
      for (int j = 0; j < point_num; ++j)
      {
        if (all_segment[i][0] == all_segment[i][2]
            && all_segment[i][1] == all_segment[i][3])
        {
          if ((all_segment[i][0] == points[j][0]
               && all_segment[i][1] == points[j][1])
              || (all_segment[i][2] == points[j][0]
                  && all_segment[i][3] == points[j][1]))
          {
            ++all_segment[i][4];
            continue;
          } 
        }
        else
        {
          if (IsLineCoincidence(all_segment[i], points[j]))
            ++all_segment[i][4];
        }
      }

    }

    int max_seg_num = 0;
    for (int i = 0; i < seg_num; ++i)
    {
      max_seg_num = max(max_seg_num, all_segment[i][4]);
    }

    return max_seg_num;
  }

  bool IsLineCoincidence(const array<int, 5> &s1, const vector<int> &p)
    {
      array<long long, 2> ab = {s1[2]-s1[0], s1[3]-s1[1]};
      array<long long, 2> ap = {p[0]-s1[0], p[1]-s1[1]};

      return ab[0]*ap[1] == ab[1]*ap[0];
    }
};


int main (int argc, char *argv[])
{
  Solution su;
  vector<vector<int>> p = {{15,12},{9,10},{-16,3},{-15,15},{11,-10},{-5,20},{-3,-15},{-11,-8},{-8,-3},{3,6},{15,-14},{-16,-18},{-6,-8},{14,9},{-1,-7},{-1,-2},{3,11},{6,20},{10,-7},{0,14},{19,-18},{-10,-15},{-17,-1},{8,7},{20,-18},{-4,-9},{-9,16},{10,14},{-14,-15},{-2,-10},{-18,9},{7,-5},{-12,11},{-17,-6},{5,-17},{-2,-20},{15,-2},{-5,-16},{1,-20},{19,-12},{-14,-1},{18,10},{1,-20},{-15,19},{-18,13},{13,-3},{-16,-17},{1,0},{20,-18},{7,19},{1,-6},{-7,-11},{7,1},{-15,12},{-1,7},{-3,-13},{-11,2},{-17,-5},{-12,-14},{15,-3},{15,-11},{7,3},{19,7},{-15,19},{10,-14},{-14,5},{0,-1},{-12,-4},{4,18},{7,-3},{-5,-3},{1,-11},{1,-1},{2,16},{6,-6},{-17,9},{14,3},{-13,8},{-9,14},{-5,-1},{-18,-17},{9,-10},{19,19},{16,7},{3,7},{-18,-12},{-11,12},{-15,20},{-3,4},{-18,1},{13,17},{-16,-15},{-9,-9},{15,8},{19,-9},{9,-17}};
  cerr << su.maxPoints(p) << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
