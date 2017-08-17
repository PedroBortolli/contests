#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll n, b;
ll f(ll x) {
	return ((n-x)/b)*x;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &b);
		ll ans = 0;
		for (ll i = 0; i <= n; i++) {
			if (f(i) > ans) {
				ans = max(ans, f(i));
				
			}
		}
		printf("%lld\n", ans);
	}
	 		

	return 0;
}