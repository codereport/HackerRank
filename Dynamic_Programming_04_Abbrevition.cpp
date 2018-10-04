// code_report Solution
// 


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
