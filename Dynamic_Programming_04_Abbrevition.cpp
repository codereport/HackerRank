// code_report Solution

// Solution 1:
// https://youtu.be/DW92IHf8KK8

#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

void rec(string A, string B);

unordered_set<string> memo;
bool possible;

auto abbreviation(string a, string b) {
   possible = false;
   memo.clear();
   rec(a, b);
   return possible ? "YES" : "NO";
}

void rec(string A, string B) {
   if (possible || A.size() < B.size()) return;
   if (B.empty()) {
      if (all_of(A.begin(), A.end(), [](auto e) { return islower(e); }))
         possible = true;
      return;
   }

   auto p = memo.insert(A + '#' + B);
   if (!p.second) return; // return if A#B already in set

   auto fc = A[0]; // first char 
   A.erase(0, 1);
   if (islower(fc)) rec(A, B);
   if (toupper(fc) != B[0]) return;
   B.erase(0, 1);
   rec(A, B);

   return;
}

// Solution 2:
// https://youtu.be/ViILdd8495M

auto abbreviation(string a, string b) {
   int n = a.size();
   int m = b.size();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1));
   dp[0][0] = 1;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
         if (!dp[i][j]) continue;
         if (j < m && toupper(a[i]) == b[j]) dp[i + 1][j + 1] = 1;
         if (!isupper(a[i]))                 dp[i + 1][j    ] = 1;
      }
   }

   return (dp[n][m] ? "YES\n" : "NO\n");
}
