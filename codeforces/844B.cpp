#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[55][55];

ll calc(int x) {
	ll anss = 1ll;
	for (int i = 1; i <= x; i++)
		anss *= 2ll;
	return anss-1ll;
}

int main() {
	int n, m;
	ll ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	int cont = 0;
	for (int i = 0; i < n; i++) {
		cont = 0;
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) cont++;
		}
		ans += calc(cont);
		cont = 0;
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) cont++;
		}
		ans += calc(cont);
	}

	for (int i = 0; i < m; i++) {
		cont = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 1) cont++;
		}
		ans += calc(cont);
		cont = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 0) cont++;
		}
		ans += calc(cont);
	}
	ans -= (n*m);

	printf("%lld\n", ans);
	return 0;
}