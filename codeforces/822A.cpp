#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll mn = min(a, b);
	ll ans = 1;
	for (ll i = 2; i <= mn; i++) {
		ans = ans*i;
	}	

	printf("%lld\n", ans);
	return 0;
}