#include <string>
#include <iostream>


using namespace std;


class Solution {
public:
    string reverseWords(string s) {
      string str;
      int front = s.size()-1;
      int back = s.size()-1;
      while (front >= 0 && s[front] == ' ')
        --front;
      back = front+1;
      while (front >= 0)
      {
        while (front >= 0 && s[front] != ' ')
          --front;
        str += s.substr(front+1, back-front-1);
        str += " ";
        
        while (front >= 0 && s[front] == ' ')
          --front;
        back = front+1;
      }

      if (!str.empty())
        str.pop_back();
      return str;
    }
};


int main (int argc, char *argv[])
{
  string s = "       the sky ! is!  blue    ";
  Solution su;
  string r = su.reverseWords(s);
  cerr << r << "||" << endl;
  cerr << "Hello World!" << endl;
  return 0;
}
