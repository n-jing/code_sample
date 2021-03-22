#include <vector>
#include <set>
#include <array>
#include <iostream>
#include <tuple>

using namespace std;







class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      long long total_area = CalculateArea(A, B, C, D) + CalculateArea(E, F, G, H);
      vector<array<long long, 2>> p = {{A, B}, {C, B}, {C, D}, {A, D}};
      if (IsPointInside(p[0][0], p[0][1], E, F, G, H)
          && IsPointInside(p[1][0], p[1][1], E, F, G, H)
          && IsPointInside(p[2][0], p[2][1], E, F, G, H)
          && IsPointInside(p[3][0], p[3][1], E, F, G, H))
        return total_area - CalculateArea(A, B, C, D);

      p = {{E, F}, {G, F}, {G, H}, {E, H}};
      if (IsPointInside(p[0][0], p[0][1], A, B, C, D)
          && IsPointInside(p[1][0], p[1][1], A, B, C, D)
          && IsPointInside(p[2][0], p[2][1], A, B, C, D)
          && IsPointInside(p[3][0], p[3][1], A, B, C, D))
        return total_area - CalculateArea(E, F, G, H);

      if (A == C || B == D || E == G || F == H)
        return total_area;

      set<array<long long, 2>> intersect_points;
      vector<array<long long, 4>> r1 = GetRectangleEdges(A, B, C, D);
      vector<array<long long, 4>> r2 = GetRectangleEdges(E, F, G, H);
      // for (auto t : r1)
      // {
      //   for (auto n : t)
      //   {
      //     cerr << n << " ";
      //   }
      //   cerr << endl;
      // }
      // cerr << "****************" << endl;
      // for (auto t : r2)
      // {
      //   for (auto n : t)
      //   {
      //     cerr << n << " ";
      //   }
      //   cerr << endl;
      // }

      for (long long i = 0; i < 4; ++i)
      {
        for (long long j = 0; j < 4; ++j)
        {
          bool intered = false;
          array<long long, 2> p = {0, 0};
          tie(intered, p) = CalculateIntersection(r1[i][0], r1[i][1], r1[i][2], r1[i][3],
                                                  r2[j][0], r2[j][1], r2[j][2], r2[j][3]);
          if (intered)
            intersect_points.insert(p);
        }
      }

      vector<array<long long, 2>> points(intersect_points.begin(), intersect_points.end());
      if (points.size() <= 1)
        return total_area;
      cerr << points.size() << endl;
      for (auto p : points)
      {
        cerr << p[0] << " " << p[1] << endl;
      }
      getchar();
      
      if (points.size() == 2)
      {
        if (!IsOneLine(points[0][0], points[0][1], points[1][0], points[1][1]))
          return total_area - CalculateArea(points[0][0], points[0][1], points[1][0], points[1][1]);
      }
      if (points.size() == 3)
      {
        long long a1 = 0;
        long long a2 = 0;
        if (IsOneLine(points[0][0], points[0][1], points[1][0], points[1][1])
            && IsOneLine(points[0][0], points[0][1], points[2][0], points[2][1]))
        {
          a1 = CalculateArea(points[1][0], points[1][1], points[0][0], points[0][1]);
          a2 = CalculateArea(points[1][0], points[1][1], points[2][0], points[2][1]);
        }
        else
        {
          a1 = CalculateArea(points[0][0], points[0][1], points[1][0], points[1][1]);
          a2 = CalculateArea(points[0][0], points[0][1], points[2][0], points[2][1]);
        }
        return total_area - (a1+a2);
      }

      if (points.size() == 2)
      {
        vector<array<long long, 2>> p = {{A, B}, {C, B}, {C, D}, {A, D}};
        for (long long i = 0; i < 4; ++i)
        {
          if (IsPointInside(p[i][0], p[i][1], E, F, G, H))
            points.push_back(p[i]);
        }
        p = {{E, F}, {G, F}, {G, H}, {E, H}};
        for (long long i = 0; i < 4; ++i)
        {
          if (IsPointInside(p[i][0], p[i][1], A, B, C, D))
            points.push_back(p[i]);
        }
      }

      long long a1 = CalculateArea(points[0][0], points[0][1], points[1][0], points[1][1]);
      long long a2 = CalculateArea(points[0][0], points[0][1], points[2][0], points[2][1]);
      long long a3 = CalculateArea(points[0][0], points[0][1], points[3][0], points[3][1]);

      return total_area - (a1+a2+a3);
    }
  bool IsPointInside(long long a, long long b, long long A, long long B, long long C, long long D)
    {
      return IsInside(a, A, C) && IsInside(b, B, D);
    }
  bool IsOneLine(long long a, long long b, long long c, long long d)
    {
      return (a == c) || (b == d);
    }
  tuple<bool, array<long long, 2>> CalculateIntersection(long long ax, long long bx, long long ay, long long by,
                                                   long long cx, long long dx, long long cy, long long dy)
    {
      if (ax == bx)
      {
        if (cx == dx)
          return {false, array<long long, 2>{0, 0}};
        if (IsInside(ax, cx, dx) && IsInside(cy, ay, by))
          return {true, array<long long, 2>{ax, cy}};
        return {false, array<long long, 2>{0, 0}};
      }
      else if (ay == by)
      {
        if (cy == dy)
          return {false, array<long long, 2>{0, 0}};
        if (IsInside(cx, ax, bx) && IsInside(ay, cy, dy))
          return {true, array<long long, 2>{cx, ay}};
        return {false, array<long long, 2>{0, 0}};
      }
      return {false, array<long long, 2>{0, 0}};
    }
  bool IsInside(long long a, long long b, long long c)
    {
      return ((a >= b) && (a <= c));
    }

  vector<array<long long, 4>> GetRectangleEdges(long long A, long long B, long long C, long long D)
    {
      array<long long, 4> ab = {A, C, B, B};
      array<long long, 4> bc = {C, C, B, D};
      array<long long, 4> dc = {A, C, D, D};
      array<long long, 4> ad = {A, A, B, D};
      return vector<array<long long, 4>>{ab, bc, dc, ad};
    }
  long long CalculateArea(long long A, long long B, long long C, long long D)
    {
      return abs(A-C) * abs(B-D);
    }
};


int main (int argc, char *argv[])
{
  Solution su;
  int a = su.computeArea(-2, -2, 2, 2, -3, -3, -2, -2);
  cerr << a << endl;

  cerr << "Hello World!" << endl;
  return 0;
}
