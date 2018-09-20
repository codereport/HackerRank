// code_report Solution
// https://youtu.be/_nLeiMMSd4E

#include <vector>

using namespace std;

const int MOD = 1000000007;

long countArray (int n, int k, int x) 
{
   vector<long long> b (n), a (n);

   a[0] = x == 1 ? 1 : 0; // ends in x
   b[0] = x == 1 ? 0 : 1; // doesn't end in x
   
   for (int i = 1; i < n; ++i) {
      a[i] = b[i - 1] % MOD;
      b[i] = (a[i - 1] * (k - 1) + b[i - 1] * (k - 2)) % MOD;
   }

   return a[n - 1];
}
