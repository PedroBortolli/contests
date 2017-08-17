#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const ll mod = 1000000007;
ll dp[5000005], close[5000005];
int pr[5000005];

ll go(ll x) {
	if (dp[x] != -1 or !pr[x]) return dp[x]%mod;
	else return dp[x] = ((x/close[x]) * go(close[x]) + go(x/close[x]))%mod;
}

int main() {
	ll t, l, r, ans = 0ll, x = 1ll;
	scanf("%lld %lld %lld", &t, &l, &r);

	memset(dp, -1, sizeof(dp));
	memset(close, -1, sizeof(close));

	for (ll i = 2; i <= 5000000; i++) {
		if (pr[i]) continue;
		if (dp[i] == -1) dp[i] = (i*(i-1ll)/2ll)%mod;
		for (ll j = i+i; j <= 5000000; j += i) {
			pr[j] = 1;
			if (close[j] == -1) close[j] = i;
		}
	}
	
	for (ll i = l; i <= r; i++) {
		ans = (ans + x*go(i))%mod;
		x = (x*t)%mod;
	}

	printf("%lld\n", ans%mod);
	return 0;
}