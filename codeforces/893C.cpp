#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


ll c[100005], seen[100005], best = 2000000000;
vector <ll> v[100005];
void dfs(ll x) {
	seen[x] = 1;
	best = min(best, c[x]);
	for (auto a : v[x]) {
		if (!seen[a])
			dfs(a);
	}
}

int main() {
	ll n, m, x, y;
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	for (ll i = 0; i < m; i++) {
		scanf("%lld %lld", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (seen[i]) continue;
		best = 2000000000;
		dfs(i);
		ans += best;
	}

	printf("%lld\n", ans);
	return 0;
}