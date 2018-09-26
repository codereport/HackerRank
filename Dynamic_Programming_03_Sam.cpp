// code_report Solution
// https://youtu.be/kXS66eP0T6s

// SOLUTION 1 - O(n^2)

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

const int MOD = 1000000007;

auto substrings (string s) {
   auto ans = 0LL;
   vector<long long> dp;
   for (auto c : s) {
      for (auto& e : dp) e *= 10, e += c - '0', e %= MOD;
      dp.push_back (c - '0');
      ans += accumulate (dp.begin (), dp.end (), 0LL) % MOD;
   }
   return ans % MOD;
}

int main () {
   string n;
   cin >> n;
   cout << substrings (n) << endl;
}

// SOLUTION 2 - O(n) - less algorithms

#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000007;

long substrings (string s) {
   int n = s.size ();
   vector<long> a (n), b (n); // a = weight, b = weight sum
   a[0] = 1, b[0] = 1;

   for (int i = 1; i < n; i++) {
      a[i] = (10 * a[i - 1]) % MOD;
      b[i] = (b[i - 1] + a[i]) % MOD;
   }

   long ans = 0;
   for (int i = 0; i < n; i++) {
      ans += ((s[i] - '0') * b[n - i - 1] * (i + 1)) % MOD;
      ans %= MOD;
   }

   return ans;
}

int main () {
   string n;
   cin >> n;
   cout << substrings (n) << endl;
}

// SOLUTION 3 - O(n) - more algorithms

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

const int MOD = 1000000007;

auto substrings (string s) {
   int n = s.size ();
   vector<long> a (n), b (n); a[0] = 1; // a = weight, b = weight sum

   generate (a.begin () + 1, a.end (), [&, i = 1LL] () mutable { i *= 10; i %= MOD; return i; });
   partial_sum (a.begin (), a.end (), b.begin (), [&](auto i, auto j) { return (i + j) % MOD; });

   auto value_add_by_digit = [&, i = 0] (auto t, auto j) mutable {
      ++i; return (t + ((j - '0') * b[n - i] * i)) % MOD;
   };

   return accumulate (s.begin (), s.end (), 0LL, value_add_by_digit);
}

int main () {
   string n;
   cin >> n;
   cout << substrings (n) << endl;
}
