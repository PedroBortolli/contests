#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <ll> v[100005];
map <pll, ll> mp;
ll seen[100005], pa[100005], dep[100005];

void dfs(ll x, ll prev, ll prof) {
	seen[x] = 1;
	pa[x] = prev;
	dep[x] = prof;
	for (auto a : v[x]) {
		if (!seen[a]) {
			dfs(a, x, prof+1);
		}
	}
}

ll lca(ll x, ll y, ll z, ll ans) {
	if (x == y) return ans;
	if (dep[y] > dep[x]) swap(x,y);
	ll ret;
	ll c = mp[mp(x,pa[x])];
	if (c <= z) {
		if (ans == -1ll) ret = c;
		else ret = ans^c;
	}
	else ret = ans;
	lca(pa[x], y, z, ret);
}

int main() {
	ll tt, n, m, x, y, z, root;
	scanf("%lld", &tt);
	while (tt--) {
		for (ll i = 0; i < 100005; i++)
			v[i].clear();
		mp.clear();
		memset(seen, 0, sizeof(seen));
		memset(pa, 0, sizeof(pa));
		memset(dep, 0, sizeof(dep));
		root = 0;
		scanf("%lld", &n);
		for (ll i = 0; i < n-1; i++) {
			scanf("%lld %lld %lld", &x, &y, &z);
			if (root == 0) root = x;
			v[x].pb(y);
			v[y].pb(x);
			mp[mp(x,y)] = z;
			mp[mp(y,x)] = z;
		}
		dfs(root, -1, 0);
		scanf("%lld", &m);
		for (ll i = 0; i < m; i++) {
			scanf("%lld %lld %lld", &x, &y, &z);
			printf("%lld\n", max(0ll, lca(x,y,z,-1ll)));
		}
	}


	return 0;
}