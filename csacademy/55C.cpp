#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[100005];
int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	ll l = 1, r = 100000000000000000, m, ans = -1;
	while (l <= r) {
		m = (l+r)/2;
		//printf("m = %lld\n", m);
		ll got = 0;
		for (ll i = 0; i < n; i++) {
			got += (v[i]/m);
		}
		if (got >= k) {
			//printf("	ok\n");
			ans = max(ans, m);
			l = m+1;
		}
		else r = m-1;
	}

	if (ans == -1) ans = 0;
	printf("%lld\n", ans);
	return 0;
}