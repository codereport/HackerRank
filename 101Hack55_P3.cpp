// code_report Solution
// 

// Original solution

long fewestTowers (vector<int> xs, vector<int> ys) 
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

   auto max_t = *max_element (t.begin (), t.end ());
   auto min_b = *min_element (b.begin (), b.end ());

   for (int i = 1;   b[i - 1] != min_b; ++i) b[i] = min (b[i], b[i - 1]);
   for (int i = 1;   t[i - 1] != max_t; ++i) t[i] = max (t[i], t[i - 1]);
   for (int i = c-2; b[i + 1] != min_b; --i) b[i] = min (b[i], b[i + 1]);
   for (int i = c-2; t[i + 1] != max_t; --i) t[i] = max (t[i], t[i + 1]);
   
   long ans = -n;
   for (auto i = 0; i < c; ++i) ans += t[i] - b[i] + 1; // could be transform

   return ans;
}

// Modern solution


template <typename I, typename P, typename F>
// requires ForwardIterator<I> &&
//          StrictWeakOrdering<P> &&
//          RangeFunction<F>
F group_equal (I f, I l, P p, F action) {
   while (f != l) {
      I cur_end = std::upper_bound (f, l, *f, p);
      action (f, cur_end);
      f = cur_end;
   }
   return action;
}

template <typename P>
void set_perimeter (std::vector<int> &v, P p) {
   auto limit = *min_element (v.begin (), v.end (), p);
   for (int i = 1;             v[i - 1] != limit; ++i) if (p (v[i - 1], v[i])) v[i] = v[i - 1];
   for (int i = v.size () - 2; v[i + 1] != limit; --i) if (p (v[i + 1], v[i])) v[i] = v[i + 1];
}

template <typename I, typename P>
void set_perimeter2 (I f, I l, P p) {
   ++f, --(--l);
   auto limit = *min_element (v.begin (), v.end (), p);
   while (*f != limit) v[i] = p (v[i - 1], v[i]) ? v[i - 1] : v[i], ++f;
   while (*l != limit) v[i] = p (v[i + 1], v[i]) ? v[i + 1] : v[i], --l;
}

long fewestTowers2 (std::vector<int> xs, std::vector<int> ys)
{
   std::vector<std::pair<int, int>> dots (xs.size ());
   std::transform (xs.begin (), xs.end (), ys.begin (), dots.begin (), [](int x, int y) { return std::make_pair (x, y); });
   std::sort (dots.begin (), dots.end ());

   std::vector<int> t, b; // top, bottom
   group_equal (dots.begin (), dots.end (), 
      [](const auto& dot1, const auto& dot2) { return dot1.first < dot2.first; },
      [&](auto f, auto l) mutable { b.push_back (f->second); t.push_back ((--l)->second); });

   set_perimeter (b, std::less<>    ());
   set_perimeter (t, std::greater<> ());

   std::vector<int> diff (t.size ());
   std::transform (t.begin (), t.end (), b.begin (), diff.begin (), std::minus<> ());
   
   return std::accumulate (diff.begin (), diff.end (), 0) + t.size () - xs.size ();
}
