#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, m, c[55];
map <pair <int, ll>, ll> dp;
ll a[55], b[55], k;
map <pair <int, ll>, pair <int, ll> > to;
const ll inf = 1e16;

ll go(int id, ll last, int comp, int used) {
	if (id == m+1) {
		if (used != n) return -inf;
		else return 0;
	}
	if (dp.find(mp(id,last)) != dp.end()) return dp[mp(id, last)];
	ll ans = -inf, aux;
	for (int i = 1; i <= m+1; i++) {
		if (i == m+1) {
			aux = go(id+1, last, comp, used);
			if (aux > ans) {
				ans = aux;
				to[mp(id, last)] = mp(i, -1);
			}
			break;
		}
		for (ll j = a[i]; j <= b[i]; j++) {
			if (!used) {
				aux = j+go(i, j, c[i], used+1);
				if (aux > ans) {
					ans = aux;
					to[mp(id, last)] = mp(i, j);
				}
			}
			else {
				if ((j == k*last or j == k+last) and c[i] > comp) {
					aux = j+go(i, j, c[i], used+1);
					//printf("j = %lld       Aux = %lld\n", j, aux);
					if (aux > ans) {
						ans = aux;
						to[mp(id, last)] = mp(i, j);
					}
				}
			}
		}
	}
	return dp[mp(id, last)] = ans;
}

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%lld %lld %d", &a[i], &b[i], &c[i]);
	if (go(0, 0, 0, 0) > 0) {
		printf("YES\n");
		int x = 0;
		ll y = 0;
		for (int i = 0; i < n; i++) {
			pair <int, ll> p = to[mp(x,y)];
			printf("%d %lld\n", p.first, p.second);
			x = p.first;
			y = p.second;
		}
	}
	else printf("NO\n");
	return 0;
}