#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[100005], a[10], dp[100005][4], n;
const ll inf = 3e18+100;
ll go(ll id, ll t) {
	if (t == 3) return 0;
	if (id == n) return -inf;
	if (dp[id][t] != -1) return dp[id][t];
	ll ans = max(go(id+1, t), v[id]*a[t] + go(id, t+1));
	return dp[id][t] = ans;
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &a[0], &a[1], &a[2]);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	memset(dp, -1, sizeof(dp));

	printf("%lld\n", go(0,0));
	return 0;
}