// code_report Solution
// 

// Original solution

#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <functional>
#include <numeric>
#include <type_traits>

using namespace std;

long fewestTowers (std::vector<int> xs, std::vector<int> ys)
{
   map<int, set<int>> xy;
   int n = xs.size ();

   for (int i = 0; i < n; ++i) {
      int x = xs[i];
      int y = ys[i];
      xy[x].insert (y);
   }

   int c = xy.size (); // cols
   vector<int> t, b;   // top, bottom
   
   for (const auto& col : xy) {
      b.push_back (*col.second.begin  ());
      t.push_back (*col.second.rbegin ());
   }

   auto j = distance (b.begin (), min_element (b.begin (), b.end ()));
   auto k = distance (t.begin (), max_element (t.begin (), t.end ()));

   for (int i = 1;   i <= j; ++i) b[i] = min (b[i], b[i - 1]);
   for (int i = 1;   i <= k; ++i) t[i] = max (t[i], t[i - 1]);
   for (int i = c-2; i >= j; --i) b[i] = min (b[i], b[i + 1]);
   for (int i = c-2; i >= k; --i) t[i] = max (t[i], t[i + 1]);
   
   long ans = -n;
   for (auto i = 0; i < c; ++i) ans += t[i] - b[i] + 1; // could be transform

   return ans;
}

// Modern solution

template <typename I, typename P, typename F>
F group_equal (I f, I l, P p, F action) {
   while (f != l) {
      I cur_end = std::upper_bound (f, l, *f, p);
      action (f, cur_end);
      f = cur_end;
   }
   return action;
}

template <typename I, typename P>
void set_perimeter (I f, I l, P p) {
   using rev  = std::reverse_iterator<I>;
   auto limit = min_element (f, l, p);
   auto min_p = [p](const auto& x, const auto& y) { return p (x, y) ? x : y; };
   std::partial_sum (f, limit, f, min_p);
   std::partial_sum (rev (l), rev (limit), rev (l), min_p);
}

long fewestTowers (std::vector<int> xs, std::vector<int> ys)
{
   std::vector<std::pair<int, int>> dots (xs.size ());
   std::transform (xs.begin (), xs.end (), ys.begin (), dots.begin (), [](int x, int y) { return std::make_pair (x, y); });
   std::sort (dots.begin (), dots.end ());

   std::vector<int> t, b; // top, bottom
   group_equal (dots.begin (), dots.end (), [](const auto& dot1, const auto& dot2) { return dot1.first < dot2.first; },
      [&](auto f, auto l) mutable { b.push_back (f->second); t.push_back ((--l)->second); });

   set_perimeter (b.begin (), b.end (), std::less<>    ());
   set_perimeter (t.begin (), t.end (), std::greater<> ());

   long ans = - (int) xs.size ();
   for (auto i = 0; i < t.size (); ++i) ans += t[i] - b[i] + 1;

   return ans;
}
