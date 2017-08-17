#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, w[1005], b[1005], seen[1005], g[1005], nxt[1005], a[1005];
pii group[1005];
ll dp[1005][1005];
const ll inf = 1e12; 
vector <int> v[1005];

void dfs(int x, int gr) {
	g[x] = gr;
	group[gr].first += w[x];
	group[gr].second += b[x];
	seen[x] = 1;
	for (auto a :v[x]) {
		if (!seen[a])
			dfs(a, gr);
	}
}

ll go(int id, int rm) {
	if (dp[id][rm] != -1) return dp[id][rm];
	if (id >= n) return 0;
	int x = g[a[id]];
	ll c1 = -inf, c2 = -inf, c3 = -inf;
	if (group[x].first <= rm) c1 = group[x].second + go(nxt[x], rm-group[x].first);
	if (w[a[id]] <= rm) c2 = b[a[id]] + go(nxt[x], rm-w[a[id]]);
	c3 = go(id+1, rm);
	return dp[id][rm] = max(max(c1, c2), c3);
}

int main() {
	int m, mxw, x, y;
	scanf("%d %d %d", &n, &m, &mxw);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	x = 1;
	for (int i = 1; i <= n; i++) {
		if (!seen[i]) {
			dfs(i, x++);
		}
	}

	int k = 0;
	for (int i = 1; i < x; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[j] == i) {
				a[k++] = j;
				nxt[i] = k;
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, mxw));
	return 0;
}