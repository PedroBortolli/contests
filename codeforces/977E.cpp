#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 2e5+5;
vector <int> v[N];
int seen[N], cont = 0, ed = 0, ok = 1;

void dfs(int x) {
	seen[x] = 1;
	cont++;
	if (v[x].size() != 2) ok = 0;
	for (auto a : v[x]) {
		ed++;
		if (!seen[a]) {
			dfs(a);
		}
	}
}

int main() {
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!seen[i]) {
			cont = 0;
			ed = 0;
			ok = 1;
			dfs(i);
			//printf("%d %d\n", cont, ed);
			if (ok && cont == ed/2) ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}