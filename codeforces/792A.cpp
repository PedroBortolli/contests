#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[200005];
map <ll, ll> f;
int main() {
	ll n;
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		f[v[i]]++;
	}

	sort(v, v+n);
	ll mn = INT_MAX;
	for (ll i = 0; i < n-1; i++)
		mn = min(mn, abs(v[i+1]-v[i]));

	printf("%lld ", mn);
	ll ans = 0;
	ll need;
	if (mn == 0) {
		ll cont = 0;
		for (auto a : f) {
			ll x = a.second;
			ans += ((x*(x-1ll))/2ll);
		}
		printf("%lld\n", ans);
		return 0;
	}

	for (ll i = 0; i < n; i++) {
		need = v[i]+mn;
		ans += f[need];
		need = v[i]-mn;
		ans += f[need];
	}

	printf("%lld\n", ans/2);



	return 0;
}