// code_report Solution
// 

void solve(int n, vector<int> a) {
    sort(begin(a), end(a), greater<int>());
    auto on  = accumulate(begin(a), begin(a) + n, 0.0);
    auto off = accumulate(begin(a) + n, end(a), 0.0);
    auto i   = 0;
    auto avg = [&]() { return (off + on) / (n - i); };
    while (avg() < a[i] && i < n) on -= a[i], ++i;
    cout << setprecision(10) << fixed << avg() << endl;
}
