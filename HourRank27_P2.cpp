// code_report Solution
// 

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

using ll = long long;

const ll MIN = numeric_limits<ll>::min ();

multiset<ll>::iterator first_less_than (const multiset<ll>& ms, ll val) {
	auto it = ms.lower_bound (val);
	if (it == ms.end ()) --it;
	while (it != ms.begin () && *it >= val) --it;
	return *it >= val ? ms.end () : it;
}

void single_erase (multiset<ll>& ms, ll val) {
	auto it = ms.find (val);
	ms.erase (it);
}

ll calc (ll a, ll b, ll c) {
	if (a == MIN || c == MIN) return MIN;
	return (a < b && b < c) ? a * b * c : MIN;
}

ll maximumProfit (const vector<ll>& v) 
{
	multiset<ll> right (v.begin (), v.end ()), left;

	ll res = MIN;

	for (int i = 0; i < v.size (); ++i)
	{
		ll a1, a2, c1, c2, b = v[i];
		single_erase (right, b);

		if (!right.empty () && !left.empty ())
		{
			a1      = *left.begin ();
			auto it = first_less_than (left, b);
			a2      = it != left.end () ? *it : MIN;
			
			it      = right.upper_bound (b);
			c1      = it != right.end () ? *it : MIN;
			c2      = *(--right.end ());

			res = max (res, calc (a1, b, c1));
			res = max (res, calc (a2, b, c1));
			res = max (res, calc (a1, b, c2));
			res = max (res, calc (a2, b, c2));
		}

		left.insert (b);
	}

	return res == MIN ? -1LL : res;
}

int main ()
{
	int n; cin >> n;
	vector<ll> profits (n);
	for (int i = 0; i < n; ++i) cin >> profits[i];

	cout << maximumProfit (profits) << endl;

	return 0;
}
