#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll a, b, c, n, dp[15005][4][4];
const ll mod = 998244353;

ll go(ll id, ll prev, ll old, ll rema, ll remb, ll remc) {
	if (dp[id][prev][id] != -1) return dp[id][prev][id];
	if (id == n) return 1ll;
	ll ans = 0;
	if (prev == 0) {
		if (rema) ans = (ans + go(id+1, 0, 0, rema-1, remb, remc) + go(id+1, 1, 0, rema-1, remb, remc))%mod;
		if (remb) ans = (ans + go(id+1, 0, 0, rema, remb-1, remc) + go(id+1, 2, 0, rema, remb-1, remc))%mod;
		if (remc) ans = (ans + go(id+1, 0, 0, rema, remb, remc-1) + go(id+1, 3, 0, rema, remb, remc-1))%mod;
	}
	else if (old == 0) {
		if (prev == 1) {
			if (remb) ans = (ans + go(id+1, 0, 0, rema, remb-1, remc) + go(id+1, 2, 1, rema, remb-1, remc))%mod;
			if (remc) ans = (ans + go(id+1, 0, 0, rema, remb, remc-1) + go(id+1, 3, 1, rema, remb, remc-1))%mod;
		}
		if (prev == 2) {
			if (rema) ans = (ans + go(id+1, 0, 0, rema-1, remb, remc) + go(id+1, 1, 2, rema-1, remb, remc))%mod;
			if (remc) ans = (ans + go(id+1, 0, 0, rema, remb, remc-1) + go(id+1, 3, 2, rema, remb, remc-1))%mod;
		}
		if (prev == 3) {
			if (rema) ans = (ans + go(id+1, 0, 0, rema-1, remb, remc) + go(id+1, 1, 3, rema-1, remb, remc))%mod;
			if (remb) ans = (ans + go(id+1, 0, 0, rema, remb-1, remc) + go(id+1, 2, 3, rema, remb-1, remc))%mod;
		}
	}
	else {
		if (prev == 1 && old == 2) ans = (ans + go(id+1, 0, 0, rema, remb, remc-1) + go(id+1, 3, 1, rema, remb, remc-1))%mod;
		if (prev == 1 && old == 3) ans = (ans + go(id+1, 0, 0, rema, remb-1, remc) + go(id+1, 2, 1, rema, remb-1, remc))%mod;
		if (prev == 2 && old == 1) ans = (ans + go(id+1, 0, 0, rema, remb, remc-1) + go(id+1, 3, 2, rema, remb, remc-1))%mod;
		if (prev == 2 && old == 3) ans = (ans + go(id+1, 0, 0, rema-1, remb, remc) + go(id+1, 1, 2, rema-1, remb, remc))%mod;
		if (prev == 3 && old == 1) ans = (ans + go(id+1, 0, 0, rema, remb-1, remc) + go(id+1, 2, 3, rema, remb-1, remc))%mod;
		if (prev == 3 && old == 2) ans = (ans + go(id+1, 0, 0, rema-1, remb, remc) + go(id+1, 1, 3, rema-1, remb, remc))%mod;
	}
	return dp[id][prev][old] = ans;
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	n = a+b+c;
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0, 0, 0, a, b, c));
	return 0;
}