// code_report Solution
// 

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
