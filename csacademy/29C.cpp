#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <ll> s;
int main() {
	ll n, k, x;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		s.insert(x);
	}

	ll ans = 0;
	while (1) {
		ll a = *(s.begin());
		ll b = *(s.rbegin());
		if (b-a <= k) break;
		ll aux = (b-a-k)/2 + ((b-a-k)%2 != 0);
		ans += aux;
		s.erase(s.find(a));
		s.erase(s.find(b));
		printf("%lld vira ", a);
		a += aux;
		printf("%lld\n", a);
		printf("%lld vira ", b);
		b -= aux;
		printf("%lld\n", b);
		s.insert(a);
		s.insert(b);
		for (auto a : s)
			printf("%lld ", a);
		printf("\n");
	}

	printf("%lld\n", ans);
	return 0;
}