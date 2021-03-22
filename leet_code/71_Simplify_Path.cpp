#include <string>
#include <stack>
#include <iostream>


using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
      stack<string> dir;
      int idx = path[0] == '/' ? 1 : 0;
      while (idx < path.size())
      {
        int next_idx = path.find("/", idx);
        string sub_dir = path.substr(idx, next_idx-idx);
        if (next_idx == string::npos)
          sub_dir = path.substr(idx);
        idx = next_idx+1;
        if (next_idx == string::npos)
          idx = path.size();
        if (sub_dir == "..")
        {
          if (!dir.empty())
            dir.pop();
        }
        else if (sub_dir == "." || sub_dir.empty())
          continue;
        else
          dir.push(sub_dir);
        if (next_idx == string::npos)
          break;
      }

      string abs_path;
      while (!dir.empty())
      {
        abs_path = "/" + dir.top() + abs_path;
        dir.pop();
      } 

      return abs_path.empty() ? "/" : abs_path;
    }
};


int main(int argc, char *argv[])
{
  string str = "/.";
  Solution su;
  cerr << su.simplifyPath(str) << endl;
  return 0;
}
