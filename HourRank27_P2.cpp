// code_report Solution
// 

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

using ll = long long;

const ll MIN = numeric_limits<ll>::min ();

template<typename T>
auto first_less_than (const T& ms, ll val) {
	auto it = ms.lower_bound (val);
	if (it == ms.end ()) --it;
	while (it != ms.begin () && *it >= val) --it;
	return *it >= val ? ms.end () : it;
}

ll calc (ll a, ll b, ll c) {
	if (a == MIN || c == MIN) return MIN;
	return (a < b && b < c) ? a * b * c : MIN;
}

ll maximumProfit (const vector<ll>& profits) 
{
	multiset<ll> right (profits.begin (), profits.end ());
	set<ll> left;

	ll res = MIN;

	for (ll b : profits)
	{
		ll a1, a2, c1, c2;
		right.erase (right.find (b));

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

