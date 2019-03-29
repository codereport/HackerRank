// code_report Solution
// Video Link: https://youtu.be/BxSRoYSNkgM
// Problem Link: https://www.hackerrank.com/contests/hackerrank-all-womens-codesprint-2019/challenges/strangely-compatible

function pairCount(t) {
    return Object.values(t).reduce((a, b) => a + (b * (b - 1)) / 2, 0)
}

function strangelyCompatible(students, m) {
    var changed = {}, same = {}
    for (var j in students) {
        var s = students[j]
        same[s] = (same[s]+1) || 1 ;
        for (var i = 0; i < m; ++i) {
            var t = s.substring(0, i) + '!' + s.substring(i+1, m)
            changed[t] = (changed[t]+1) || 1 ;
        }
    }
    return pairCount(changed) - pairCount(same) * m
}
