#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll l, r, x, y, k;
	scanf("%lld %lld %lld %lld %lld", &l, &r, &x, &y, &k);
	for (ll i = l; i <= r; i++) {
		if (i%k) continue;
		ll need = i/k;
		if (need >= x && need <= y) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}