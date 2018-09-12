// code_report Solution
// https://youtu.be/rdlzz2GOcq4

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int equal (vector<int> a) {
   auto min_ = *min_element (a.begin (), a.end ());
   auto ans = numeric_limits<int>::max ();
   for (auto i = 0; i < 5; i++) {
      auto operations = [min_, i](auto init, auto j) {
         auto t = j - (min_ - i);
         return init + t / 5 + t % 5 / 2 + t % 5 % 2;
      };
      ans = min (ans, accumulate (a.begin (), a.end (), 0, operations));
   }
   return ans;
}
