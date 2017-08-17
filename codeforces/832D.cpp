#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[200005];
int seen[200005], prof[200005], mp[200005], a[5], k = 0;
pii aux[200005], dp[200005][20];

void dfs(int x, int d) {
	seen[x] = 1;
	prof[x] = d;
	for (auto a : v[x]) {
		if (!seen[a]) {
			mp[x] = k;
			aux[k++] = mp(prof[x], x);
			dfs(a, d+1);
		}
	}
	mp[x] = k;
	aux[k++] = mp(prof[x], x);
}

int query(int l, int r) {
	int dif = r-l+1;
	if (dif == 1) return dp[l][0].second;
	int x = 1;
	int pot = 0;
	while (1) {
		x *= 2;
		if (x > dif) break;
		pot++;
	}
	x /= 2;
	if (dp[l][pot].first <= dp[r-x+1][pot].first) return dp[l][pot].second;
	return dp[r-x+1][pot].second;
}

int lca(int x, int y) {
	int l = mp[x];
	int r = mp[y];
	if (l > r) swap(l,r);
	return query(l,r);
}

int calc(int a, int b, int c) {
	bool x = lca(a, b) == a, y = lca(a,c) == a;
	if (x != y) return 0;
	if (x) return max(0, prof[lca(b,c)] - prof[a]);
	else if (lca(a,b) != lca(a,c)) return max(0, prof[a] - max(prof[lca(a,b)], prof[lca(a,c)]));
	else return max(0, prof[a] + prof[lca(b,c)] - 2*prof[lca(a,c)]);
}

int main() {
	int n, q, x, y, z;
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		v[i].pb(x);
		v[x].pb(i);
	}

	dfs(1, 0);

	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < k; i++) {
			if (j == 0) {
				dp[i][j].first = aux[i].first;
				dp[i][j].second = aux[i].second;
			}
			else {
				int pot = 1 << j;
				if (i + pot > k) continue;
				int a = dp[i][j-1].first;
				int ida = dp[i][j-1].second;
				int b = dp[i+pot/2][j-1].first;
				int idb = dp[i+pot/2][j-1].second;
				if (a <= b) {
					dp[i][j].first = a;
					dp[i][j].second = ida;
				}
				else {
					dp[i][j].first = b;
					dp[i][j].second = idb;
				}
			}
		}
	}

	while (q--) {
		int ans = 0;
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		printf("%d\n", 1 + max(calc(a[0],a[1],a[2]), max(calc(a[1],a[0],a[2]), calc(a[2],a[1],a[0]))));
	}

	return 0;
}
