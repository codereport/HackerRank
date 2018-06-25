// code_report Solution
// https://youtu.be/HEizjKb7LjY

static int minuteToWinIt(int[] a, int k) {
    Integer ans = n-1;
    Long j = 0L;
    HashMap<Long, Integer> m = new HashMap<Long, Integer> ();
    for (int e : a) {
        m.put (e - j, m.getOrDefault (e - j, 0) + 1);
        j += k;
    }
    for (Map.Entry<Long, Integer> e : m.entrySet ()) ans = Math.min (ans, n - e.getValue ());
    return ans;
}
