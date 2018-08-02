// code_report Solution
// https://youtu.be/YHoEJ_UhG1Y

#include <vector>
#include <string>

using namespace std;

#define FORI(s,n) for(int i = s; i < n; i++)
#define FORJ(s,n) for(int j = s; j < n; j++)

string solve (vector<vector<int>> b) 
{
   int n = b.size ();
   FORI (0, n) FORJ (1, n) if (b[i][j] == b[i][j - 1]) return "No";
   FORI (0, n) FORJ (1, n) if (b[j][i] == b[j - 1][i]) return "No";
   return "Yes";
}
