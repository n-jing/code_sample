#include <vector>
#include <iostream>
#include <set>



using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<set<int>> course_prev(numCourses);
      for (const auto &p : prerequisites)
      {
        course_prev[p[0]].insert(p[1]);
      }

      vector<int> course;
      set<int> selected;
      while (course.size() != numCourses)
      {
        int c = SelectCourse(course_prev, selected);
        if (c == -1)
          return {};
        course.push_back(c);
        selected.insert(c);
        for (int r = 0; r < numCourses; ++r)
        {
          course_prev[r].erase(c);
        }
      }

      return course;
    }

  int SelectCourse(vector<set<int>> &course_prev, set<int> &selected)
    {
      const int n = course_prev.size();
      for (int i = 0; i < n; ++i)
      {
        if (course_prev[i].empty() && !selected.count(i))
          return i;
      }

      return -1;
    }
};

int main (int argc, char *argv[])
{
  Solution su;
  
  cerr << "Hello World!" << endl;
  return 0;
}
