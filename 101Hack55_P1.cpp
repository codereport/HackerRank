// code_report Solution
// https://youtu.be/Zr4sMtgCsao

#include <vector>
#include <algorithm>

using namespace std;

int swapToSort (vector<int> a) 
{
   if (is_sorted (a.begin (), a.end ())) return 0;
   int n = a.size ();
   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         swap (a[i], a[j]);
         if (is_sorted (a.begin (), a.end ())) return 1;
         swap (a[i], a[j]);
      }
   }
   return -1;
}
