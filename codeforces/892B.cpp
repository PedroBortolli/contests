#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[1000005], s[1000005], sum[1000005];
int main() {
	ll n;
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	for (ll i = n-1; i >= 0; i--) {
		ll x = i-v[i];
		if (x < 0) x = 0;
		s[x]++;
		s[i]--;
	}

	sum[0] = s[0];
	for (ll i = 1; i < n; i++) {
		sum[i] = sum[i-1]+s[i];
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (sum[i]) ans++;
	}

	printf("%lld\n", n-ans);
	return 0;
}