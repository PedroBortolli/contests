#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, m, c0, d0, dp[15][1005], a[15], b[15], c[15], d[105];

int go(int id, int left) {
	if (dp[id][left] != -1) return dp[id][left];
	if (id == m+1) return 0;
	int ans = 0;
	if (id == 0) {
		int cont = -1;
		for (int i = 0; i <= left; i += c0) {
			cont++;
			if (i == 0) ans = max(ans, go(id+1, left));
			else ans = max(ans, max(cont*d0+go(id+1, left-cont*c0), go(id+1, left)));
		}
	}
	else {
		int cont = -1;
		for (int i = 0; i <= a[id]; i += b[id]) {
			cont++;
			if (i == 0 or cont*c[id] > left) ans = max(ans, go(id+1, left));
			else ans = max(ans, max(cont*d[id]+go(id+1, left-cont*c[id]), go(id+1, left)));
		}
	}
	return dp[id][left] = ans;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &c0, &d0);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, n));
	return 0;
}