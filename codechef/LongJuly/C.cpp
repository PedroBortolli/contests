#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll n, b;

ll f(ll r) {
	return r*(n-r*b);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &b);
		ll l = 1, r = n/b-1, m, ans = 0;
		if (n <= b) {
			printf("0\n");
			goto here;
		}
		if (r < l) {
			printf("%lld\n", n-b);
			goto here;
		}
		while (l <= r) {
			m = (l+r)/2;
			ll x = f(m);
			ll y = f(m+1);
			ans = max(ans, max(x,y));
			if (x > y) l = m+1;
			else r = m-1;
		}
		printf("%lld\n", ans);
		here:;
	}
	return 0;
}