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

auto create_adjacency_list (int n, const vvi &edges) {
   vvi al (n);
   for (const auto& e : edges) {
      int x = e[0] - 1, y = e[1] - 1;
      al[x].push_back (y);
      al[y].push_back (x);
   }
   return al;
}

auto determine_components (int n, const vvi &al) {
   vi c (n, -1);
   for (int i = 0; i < n; ++i) 
      int j = dfs (al, c, i, i);
   return c;
}

auto find_min_max_edges (int n, const vvi &al, const vi &c) {
   unordered_map<int, pair<ll, ll>> m;

   // initialize min/max for each component
   for (const auto& e : c) {
      m[e] = { 0, n };
   }

   // find min and max edges for each component
   for (int i = 0; i < n; i++) {
      auto& p = m[c[i]];
      p.first = max (p.first, (ll)al[i].size ());
      p.second = min (p.second, (ll)al[i].size ());
   }

   return m;
}

int solve (int n, vvi edges, int a, int b)
{
   auto al = create_adjacency_list (n, edges);
   auto c  = determine_components  (n, al);
   auto m  = find_min_max_edges    (n, al, c);

   auto criteria = [&, i = 0] (const auto& edges) mutable {
      auto v_e = edges.size ();
      auto p = m[c[i]]; i++; 
      return (a * p.second < v_e && v_e < b * p.first);
   };

   return count_if (al.begin (), al.end (), criteria);
}
