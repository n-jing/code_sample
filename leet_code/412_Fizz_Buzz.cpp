class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string> vec;
      for (int i = 1; i <= n; ++i)
      {
        if (i % 3 == 0 && i % 5 == 0)
          vec.emplace_back(string("FizzBuzz"));
        else if (i % 3 == 0)
          vec.emplace_back(string("Fizz"));
        else if (i % 5 == 0)
          vec.emplace_back(string("Buzz"));
        else
          vec.emplace_back(to_string(i));
      }

      return vec;
    }
};
