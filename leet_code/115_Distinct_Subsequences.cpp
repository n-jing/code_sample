#include <vector>
#include <set>
#include <array>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;




class Solution {
public:
    int numDistinct(string s, string t) {
      set<char> char_in_t;
      for (char c : t)
      {
        if (!char_in_t.count(c))
          char_in_t.insert(c);
      }

      string str;
      for (char c : s)
      {
        if (char_in_t.count(c))
          str += c;
      }

      const long TN = t.size();
      const long SN = str.size();
      vector<array<long, 2>> sub;
      vector<long> sub_sum;
      for (long i = 0; i < TN; ++i)
      {
        vector<array<long, 2>> sub_next;
        for (long j = SN-1; j >= 0;)
        {
          while (j >= 0 && str[j] != t[i])
            --j;
          if (j == -1)
            break;
          long idx = 0;
          long count = i == 0 ? 1 : 0;
          while (idx < sub.size() && sub[idx][0] < j)
          {
            count += sub[idx][1];
            ++idx;
          }
          sub_next.push_back(array<long, 2>{j, count});
          --j;
        }
        reverse(sub_next.begin(), sub_next.end());
        sub = sub_next;
        if (sub.empty())
          return 0;
      }

      int count = 0;
      for (const auto &s : sub)
      {
        count += s[1];
      }
      
      return count;
    }
};


#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
  Solution su;
  string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
  string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";

  int num = su.numDistinct(s, t);
  cerr << num << endl;
  return 0;
}
