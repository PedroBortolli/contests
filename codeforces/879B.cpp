#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[505];
int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &v[i]);

	for (ll i = 0; i < n; i++) {
		ll pos = (i+1)%n, cont = 0;
		for (ll j = 0; j < n-1; j++) {
			if (v[pos] < v[i]) cont++;
			else break;
			pos = (pos+1)%n;
		}
		if (cont >= k) {
			printf("%lld\n", v[i]);
			return 0;
		}
	}

	printf("%lld\n", n);
	return 0;
}