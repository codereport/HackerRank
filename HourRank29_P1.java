// code_report Solution
// https://youtu.be/YHoEJ_UhG1Y

static String solve(List<List<Integer>> b) 
{
    int n = b.size ();
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (b.get (i).get (j) == b.get (i).get (j - 1)) return "No";
            if (b.get (j).get (i) == b.get (j - 1).get (i)) return "No";
        }
    }
    return "Yes";
}
