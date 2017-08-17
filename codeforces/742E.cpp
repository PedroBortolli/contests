#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int cor[200005], x[100005], y[100005];
vector <int> v[200005];

void dfs(int x, int c) {
	cor[x] = c;
	int nxt;
	if (c == 1) nxt = 2;
	else nxt = 1;
	for (auto a : v[x]) {
		if (!cor[a])
			dfs(a, nxt);
	}
}

int main() {
	int n, k = 1;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		v[k].pb(k+1);
		v[k+1].pb(k);
		k += 2;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
	}

	for (int i = 1; i <= 2*n; i++) {
		if (!cor[i])
			dfs(i, 0);
	}

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", cor[x[i]], cor[y[i]]);
	}
	return 0;
}