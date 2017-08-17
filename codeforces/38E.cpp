#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll n, x, y, dp[3005][3005];
pll v[3005];

ll go(ll id, ll last) {
	if (id == n) return 0ll;
	if (dp[id][last] != -1) return dp[id][last];
	return dp[id][last] = min(v[id].second+go(id+1, id), v[id].first-v[last].first+go(id+1, last));
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		v[i] = mp(x,y);
	}
	sort(v, v+n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", v[0].second+go(1, 0));
	return 0;
}