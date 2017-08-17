#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[100005];
int seen[100005], ok = 1;
void dfs(int x, int last) {
	seen[x] = 1;
	for (auto a : v[x]) {
		if (a == last) continue;
		else {
			if (seen[a]) ok = 0;
			else dfs(a, x);
		}
	}
}

int main() {
	int n, m, x , y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ok = 1;
		if (!seen[i]) {
			dfs(i, -1);
			ans += ok;
		}
	}

	printf("%d\n", ans);
	return 0;
}