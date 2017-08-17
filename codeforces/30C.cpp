#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll n, x[1005], y[1005], t[1005];
double p[1005], dp[1005];

double go(ll id, ll ok) {
	if (id == n+1) return 0.0;
	if (dp[id] != -1.0) return dp[id];
	double ans = 0.0;
	for (ll i = 1; i <= n; i++) {
		if (i == id) continue;
		if (!ok) ans = max(ans, p[i]+go(i, 1));
		else {
			ll dist = (x[id]-x[i])*(x[id]-x[i]) + (y[id]-y[i])*(y[id]-y[i]);
			if ((t[i]-t[id])*(t[i]-t[id]) >= dist && t[i] >= t[id]) ans = max(ans, p[i]+go(i, 1));
		}
	}
	return dp[id] = ans;
}

int main() {
	scanf("%lld", &n);
	dp[0] = -1.0;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld %lld %lf", &x[i], &y[i], &t[i], &p[i]);
		dp[i] = -1.0;
	}
	double ans = 0.0;
	printf("%.10lf\n", go(0, 0));
	return 0;
}