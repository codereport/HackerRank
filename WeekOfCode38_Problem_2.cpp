// code_report Solution
// https://youtu.be/HEizjKb7LjY

#include <vector>
#include <algorithm>
#include <unordered_map>

int minuteToWinIt (vector<int> a, int k) 
{
   long long j = 0;
   unordered_map<long long, int> m;
   for (auto e : a) ++m[e - j], j += k;
   auto compare_values = [](auto a, auto b) { return a.second < b.second; };
   return a.size () - max_element (m.begin (), m.end (), compare_values)->second;
}
