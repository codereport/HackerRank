// code_report Solution
// https://youtu.be/KDuPh7QRc88

#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>

using namespace std;

long long leastTimeToInterview (int n, int k, int m)
{
   vector<set<pair<int, int>>> v (n + 1); // first = time, second = stop #

   while (m--) {
      int i, j, t; cin >> i >> j >> t;
      v[i].insert ({ t, j });
      v[j].insert ({ t, i });
   }

   set<pair<int, int>> s ({ { 0,1 } });
   unordered_set<int> done;

   while (true)
   {
      auto cs = *s.begin (); // cs = current stop
      s.erase (s.begin ());
      if (cs.second == n) return cs.first;
      done.insert (cs.second);

      for (auto ns : v[cs.second]) { // ns = next stop
         if (done.count (ns.second)) continue;
         auto t = cs.first + ns.first;
         if (ns.second != n && (t / k) % 2 == 1) t = (t / k + 1) * k;
         s.insert ({ t, ns.second });
      }
   }
}
