#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll a[100005], temp[100005];
int main() {
	ll n, s;
	scanf("%lld %lld", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}

	ll l = 0, r = n+1, m;
	ll ans = 0, c = 4e18+5;
	while (l < r) {
		m = (l+r)/2;
		if (m == n+1) break;
		for (int i = 1; i <= n; i++) {
			temp[i] = a[i] + m*i;
		}
		
		sort(temp+1, temp+n+1);
		ll cost = 0;
		for (int i = 1; i <= m; i++) {
			cost += temp[i];
		}
		if (cost <= s) {
			ans = m;
			c = cost;
			l = m+1;
		}
		else r = m;
	}

	if (c == 4e18+5) c = 0;
	printf("%lld %lld\n", ans, c);
	return 0;
}