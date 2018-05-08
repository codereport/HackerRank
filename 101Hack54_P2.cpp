// code_report Solution
// https://youtu.be/OZXNM0qK17A

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

using ld = long double;

ld time_to_end (ld pos, ld stop, ld last_stop, ld v, ld t, ld w, ld s) 
{
   ld walk_time           = abs (pos - stop) / s;
   ld time_arrive_at_stop = t + walk_time;
   ld bus_arrival_offset  = stop / v;
   ld bus_number          = max ((ld) 0, ceil ((time_arrive_at_stop - bus_arrival_offset) / w));
   ld time_get_on_bus     = bus_number * w + bus_arrival_offset;
   ld time_on_bus         = (last_stop - stop) / v;
   
   return time_get_on_bus + time_on_bus;
}

void solve (vector<ld> stops, ld w, ld v, ld q) 
{
   while (q--) {
      ld pos, t, s;
      cin >> pos >> t >> s;
      auto ans = numeric_limits<ld>::max ();
      auto it  = upper_bound (stops.begin (), stops.end (), pos);

      if (it != stops.end   ()) ans = min (ans, time_to_end (pos, *it,        stops.back (), v, t, w, s));
      if (it != stops.begin ()) ans = min (ans, time_to_end (pos, *prev (it), stops.back (), v, t, w, s));
      ans = min (ans, (stops.back () - pos) / s + t);

      cout << fixed << setprecision (10) << ans << endl;
   }
}

int main ()
{
   int n, q; cin >> n;
   vector<ld> stops (n);
   for (int i = 0; i < n; ++i) cin >> stops[i];
   ld w, v; cin >> w >> v >> q;
   
   solve (stops, w, v, q);

   return 0;
}
