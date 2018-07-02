// code_report Solution
// https://youtu.be/xonmFdwR-Ew

#include <vector>

using namespace std;

long long minimumSum (vector<int> l, vector<int> r) 
{
   int a = l[0], b = r[0];
   long long ans = 0;

   for (int i = 1; i < l.size (); ++i) {
      int c = l[i], d = r[i];
      if      (c > b) ans += c - b, a = c, b = c;
      else if (d < a) ans += a - d, a = d, b = d;
      else {
         if (c > a) a = c;
         if (d < b) b = d;
      }
   }
   
   return ans;
}
