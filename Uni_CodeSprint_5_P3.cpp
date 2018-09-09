// code_report Solution
// 

using vi  = vector<int>;
using vvi = vector<vi>;
using ll  = long long;

int dfs (const vvi& al, vi& c, int i, int group) {
   if (c[i] != -1) return -1;
   c[i] = group;
   for (const auto& node : al[i]) dfs (al, c, node, group);
   return group;
}

int solve (int n, vvi edges, int a, int b) {
   vvi al (n); // adjacency list
   for (const auto& e : edges) {
      int x = e[0] - 1, y = e[1] - 1;
      al[x].push_back (y);
      al[y].push_back (x);
   }

   unordered_map<int, pair<ll, ll>> m;

   // dfs to find different components
   vi c (n, -1); // components
   for (int i = 0; i < n; ++i) {
      int j = dfs (al, c, i, i);
      if (j != -1) m[j] = { 0, n };
   }

   // find min and max edges for each component
   for (int i = 0; i < n; i++) {
      auto& p  = m[c[i]];
      p.first  = max (p.first, (ll)al[i].size ());
      p.second = min (p.second, (ll)al[i].size ());
   }

   auto criteria = [&, i = 0] (const auto& t) mutable {
      auto s = t.size ();    // edges of v
      auto p = m[c[i]]; i++; // min and max edges (for a node) for the component
      return (s > a * p.second && s < b * p.first);
   };

   return count_if (al.begin (), al.end (), criteria);
}
