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
	ll n, f, k, l;
	scanf("%lld %lld", &n, &f);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &k, &l);
		if (k >= l) {
			ans += l;
		}
		else {
			ans += k;
			if (2ll*k <= l) s.insert(k);
			else s.insert(l-k);
		}
	}

	int cont = 0;
	for (set <ll>::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
		if (cont == f) break;
		int a = *it;
		if (a <= 0ll) break;
		ans += a;
		cont++;
	}

	printf("%lld\n", ans);
	return 0;
}