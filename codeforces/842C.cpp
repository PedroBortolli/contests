#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int at[200005], dp[200005][2];
vector <int> v[200005];

int go(int x, int ch, int gc, int prev) {
	if (dp[x][ch] != -1) return dp[x][ch];
	int cur = __gcd(gc, at[x]), curchange = gc;
	if (ch == 0) {
		for (auto a : v[x]) {
			if (a != prev) {
				go(a, 1, curchange, x);
			}
		}
	}
	for (auto a : v[x]) {
		if (a != prev) {
			go(a, ch, cur, x);
		}
	}
	return dp[x][ch] = max(cur, curchange);
}

int main() {
	int n, x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &at[i]);
	}

	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	memset(dp, -1, sizeof(dp));
	go(1, 0, 0, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d ", max(dp[i][0], dp[i][1]));
	}
	printf("\n");
	return 0;
}