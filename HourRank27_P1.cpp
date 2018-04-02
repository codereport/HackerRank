// code_report Solution
// https://youtu.be/GzJereQHbJE

#include <vector>
#include <algorithm>

using namespace std;

string canModify (vector<int> a) 
{
	if (a.size () == 1) return "YES";

	vector<int> b = a;

	for (int i = 1; i < a.size (); ++i) {
		if (a[i] < a[i - 1]) {
			a[i - 1] = i > 1 ? a[i - 2] : 1;
			b[i]     = b[i - 1];
			break;
		}
	}

	return ((is_sorted (a.begin (), a.end ()) || is_sorted (b.begin (), b.end ())) ? "YES" : "NO");
}
