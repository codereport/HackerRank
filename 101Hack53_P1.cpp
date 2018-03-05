// code_report Solution
// https://youtu.be/xjLXiNlStMQ?t=3m26s

#include <vector>
#include <string>

using namespace std;

string berthType (int n) {
	vector<string> v = { "SUB", "LB", "MB", "UB", "LB", "MB", "UB", "SLB" };
	return v[n % 8];
}
