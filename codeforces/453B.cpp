#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, ar[111], nop[66], mp[18], rev[66], res[101];
pii dp[101][(1 << 17) + 2];
vector <pii> can[(1 << 17) + 2];
vector <int> v;

pii go(int id, int mask) {
	if (id == n) return mp(0, 0);
	if (dp[id][mask].first != -1) return dp[id][mask];
	int ans = INT_MAX, ret = 0;
	int len = (int)can[mask].size();
	for (int i = 0; i < len; i++) {
		int y = can[mask][i].first;
		if (y > ar[id]*2) break;
		int x = can[mask][i].second;
		int anss = abs(ar[id]-y)+go(id+1, x).first;
		if (anss < ans) {
			ans = anss;
			ret = y;
		}
	}
	return dp[id][mask] = mp(ans, ret);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	for (int i = 2; i <= 59; i++) {
		for (int j = i+i; j <= 59; j += i)
			nop[j] = 1;
	}
	for (int i = 2; i <= 59; i++) {
		if (!nop[i]) v.pb(i);
	}

	int cont = 0;
	for (auto a : v) {
		rev[a] = cont;
		mp[cont++] = a;
	}

	int lim = 1 << 17;
	for (int k = 0; k < lim; k++) {
		vector <int> div;
		for (int i = 0; i < 17; i++) {
			int p = 1 << i;
			if (k & p) div.pb(mp[i]);
		}
		for (int j = 1; j <= 59; j++) {
			int ok = 1;
			for (auto a : div) {
				if (j%a == 0) {
					ok = 0;
					break;
				}
			}
			if (!ok) continue;
			int aux = k;
			for (auto a : v) {
				if (j%a == 0)
					aux |= (1 << rev[a]);
			}
			can[k].pb(mp(j, aux));
		}
	}
	
	memset(dp, -1, sizeof(dp));
	go(0, 0);

	int mask = 0;
	for (int i = 0; i < n; i++) {
		int x = dp[i][mask].second;
		printf("%d ", x);
		for (auto a : v) {
			if (x%a == 0)
				mask |= (1 << rev[a]);
		}
	}
	printf("\n");
	return 0;
}