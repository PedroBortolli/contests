#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5+5;
const ll mod = 1e9+7;
int dp[1 << 19][71];
ll cnt[77], pr[25], nope[77], msk[77], fat[N], odd[77], even[77], pot[N];

ll go(ll mask, ll x) {
	if (dp[mask][x] != -1) return dp[mask][x];
	if (x > 70) {
		if (!mask) return 1;
		else return 0;
	}
	ll ans = 0;
	if (!cnt[x]) ans = go(mask, x+1)%mod;
	else ans = (pot[cnt[x]-1]*go(mask^msk[x], x+1))%mod + (pot[cnt[x]-1]*go(mask, x+1))%mod;
	return dp[mask][x] = ans%mod;
}

void build_primes() {
	for (int i = 2; i <= 70; i++) {
		for (int j = i+i; j <= 70; j += i) {
			nope[j] = 1;
		}
	}
	int k = 0;
	for (int i = 2; i <= 70; i++) {
		if (!nope[i]) pr[k++] = i;
  	}

	for (int j = 1; j <= 70; j++) {
		ll m = 0, x = j;
		for (ll i = 0; i < 19; i++) {
			int cont = 0;
			while (x > 1) {
				if (x%pr[i]) break;
				x /= pr[i];
				cont++;
			}
			if (cont%2) m += (1 << i);
		}
		msk[j] = m;
	}
}

int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}

	fat[0] = 1ll, pot[0] = 1ll;
	for (ll i = 1; i <= 100000; i++) {
		fat[i] = (fat[i-1]*i)%mod;
		pot[i] = (pot[i-1]*2ll)%mod;
	}
	build_primes();
	memset(dp, -1, sizeof(dp));
	ll ans = go(0, 1)-1;
	if (ans < 0) ans = mod-1;
	printf("%lld\n", ans);
	return 0;
}
