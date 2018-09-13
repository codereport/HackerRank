// code_report Solution
// https://youtu.be/rdlzz2GOcq4

static int equal(int[] a) {
    int min = Arrays.stream(a).min().getAsInt();
    int ans = Integer.MAX_VALUE;
    for (int i = 0; i < 5; ++i) {
        int ops = 0;
        for (int j = 0; j < a.length; ++j) {
            int t = a[j] - (min - i);
            ops  += t/5 + t%5/2 + t%5%2;
        }
        ans = Math.min(ans, ops);
   }
   return ans;
}
