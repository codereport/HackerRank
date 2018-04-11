// code_report Solution
// 

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

using namespace std;

int main () 
{
   int n, q, x, y;
   cin >> n >> q;

   vector<long long> a (n), b (n), sum_a = { 0 }, sum_b = { 0 };

   for (int i = 0; i < n; i++) 
   {
      cin >> x >> y;
      a[i] = x + y;
      b[i] = x - y;
   }
   
   sort (a.begin (), a.end ());
   sort (b.begin (), b.end ());

   partial_sum (a.begin (), a.end (), back_inserter (sum_a));
   partial_sum (b.begin (), b.end (), back_inserter (sum_b));

   while (q--) 
   {
      long long target_a, target_b, ans = 0;
      cin >> x >> y;

      target_a = x + y;
      target_b = x - y;
      
      int idx = distance (a.begin (), lower_bound (a.begin (), a.end (), target_a));

      ans += idx * target_a - sum_a[idx];
      ans += sum_a.back () - sum_a[idx] - (n - idx) * target_a;

      idx = distance (b.begin (), lower_bound (b.begin (), b.end (), target_b));

      ans += idx * target_b - sum_b[idx];
      ans += sum_b.back () - sum_b[idx] - (n - idx) * target_b;

      cout << ans / 2 << endl;
   }

   return 0;
}
