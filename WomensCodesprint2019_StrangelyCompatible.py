# code_report Solution
# Video Link: https://youtu.be/BxSRoYSNkgM
# Problem Link: https://www.hackerrank.com/contests/hackerrank-all-womens-codesprint-2019/challenges/strangely-compatible

def pair_count(t):
  return sum((i*(i-1))//2 for i in t.values())

def strangelyCompatible(students, m):
  changed, same = {}, {}
  for s in students:
    same[s] = same.get(s, 0) + 1
    for i in range(m):
      t = s[:i] + '!' + s[i+1:]
      changed[t] = changed.get(t, 0) + 1

  return pair_count(changed) - pair_count(same) * m
