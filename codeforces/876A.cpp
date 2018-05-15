#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, a, b, c, dp[105][4];

int go(int got, int id) {
	if (dp[got][id] != -1) return dp[got][id];
	if (got == n) return 0;
	int ans = 0;
	if (id == 1) ans = min(a + go(got+1, 2), b + go(got+1, 3));
	else if (id == 2) ans = min(a + go(got+1, 1), c + go(got+1, 3));
	else ans = min(b + go(got+1, 1), c + go(got+1, 2));
	return dp[got][id] = ans; 
}

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &c);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 1));
	return 0;
}