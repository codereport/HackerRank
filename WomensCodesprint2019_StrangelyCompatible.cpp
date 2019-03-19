// code_report Solution
// Video Link: https://youtu.be/BxSRoYSNkgM
// Problem Link: https://www.hackerrank.com/contests/hackerrank-all-womens-codesprint-2019/challenges/strangely-compatible

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

using namespace std;

template <typename T>
auto pair_count(T const& t) {
  return accumulate(t.begin(), t.end(), 0LL,
    [](auto a, auto b) { return a + (b.second * (b.second-1))/2; });
}

auto strangelyCompatible(vector<string> students, int m) {
  unordered_map<string, long long> changed, same;
  for (auto& student : students) {
    same[student]++;
    for (auto& letter : student) {
      auto c = letter;
      letter = '!';
      changed[student]++;
      letter = c;
    }
  }
  return pair_count(changed) - pair_count(same) * m;
}

int main()
{
  int n, m; cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  cout << strangelyCompatible(v, m) << endl;
}
