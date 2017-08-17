#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <ll> a, b;
ll v[55555];
int main() {
	ll x, y, l, r;
	cin >> x >> y >> l >> r;

	a.insert(1ll);
	b.insert(1ll);
	double aux = x;
	ll m = x;
	while (1) {
		a.insert(x);
		aux *= (double)m;
		if (aux > 2e18) break;
		x *= m;
	}

	m = y;
	aux = y;
	while (1) {
		b.insert(y);
		aux *= (double)m;
		if (aux > 2e18) break;
		y *= m;
	}

	int k = 0;
	set <ll> s;
	for (auto it : a) {
		for (auto itt : b) {
			s.insert(it+itt);
		}
	}

	s.insert(r+1ll);
	s.insert(l-1ll);
	
	for (auto it : s) {
		v[k++] = it;
	}

	ll ans = 0;
	for (int i = 0; i < k; i++) {
		if ((ll)v[i] > (ll)r) break;
		ll aux, aux2;
		if ((ll)v[i] < (ll)l) aux = (ll)l;
		else aux = (ll)v[i];
		if (s.find(aux) != s.end()) aux++;
		if (i == k-1) aux2 = (ll)r;
		else if ((ll)v[i+1] > (ll)r) aux2 = (ll)r;
		else if ((ll)v[i+1] < (ll)l) continue;
		else aux2 = (ll)v[i+1];
		if (s.find(aux2) != s.end()) aux2--;
		ans = max(ans, aux2-aux+1ll);
	}

	printf("%lld\n", ans);
	return 0;
}