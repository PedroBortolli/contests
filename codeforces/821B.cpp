#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll sum[10000007];
int main() {
	ll m, b;
	scanf("%lld %lld", &m, &b);
	ll y = b;
	ll x = b*m;
	ll ans = 0;
	for (ll i = 1; i <= 10000005; i++) {
		sum[i] = sum[i-1]+i;
	}


	for (; y >= 0; y--) {
		ll xx = m*b-m*y;
		ll idk = y+xx;
		ll aux = max(0ll, y-1ll);
		ll s = sum[idk]-sum[aux];
		ll tot = ((s + s - y*(xx+1))*(y+1))/2;
		ans = max(ans, tot);
	}

	printf("%lld\n", ans);
	return 0;
}