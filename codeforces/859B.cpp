#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll n;
	while (scanf("%lld", &n) != EOF) {
		ll l = 1, r = 1, prev = 1, turn = 0;
		while (1) {
			ll x = l*r;
			if (x > n) break;
			prev = x;
			if (!turn) {
				l++;
				turn = 1;
			}
			else {
				r++;
				turn = 0;
			}
		}

		if (turn) l--;
		else r--;
		ll ans = 8 + (l-2)*2 + (r-2)*2;
		if (n - prev > 0) ans += 2;
		printf("%lld\n", ans);
	}
	return 0;
}