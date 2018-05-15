#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

deque <ll> q;

ll check() {
	ll ok = 1;
	ll k = 0, prev = 0;
	for (auto a : q) {
		if (!k) {
			prev = a;
			k = 1;
			continue;
		}
		if (prev < a) {
			ok = 0;
			break;
		}
		prev = a;
	}
	return ok;
}

int main() {
	ll n, k, x;
	scanf("%lld %lld", &n, &k);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &x);
		q.push_back(x);
	}

	ll cont = 0;
	while (1) {
		if (check()) {
			printf("%lld\n", n);
			return 0;
		}
		ll a = q.front();
		q.pop_front();
		ll b = q.front();
		q.pop_front();
		if (a > b) {
			cont++;
			if (cont >= k) {
				printf("%lld\n", a);
				return 0;
			}
			q.push_front(a);
			q.push_back(b);
		}
		else {
			cont = 0;
			q.push_front(b);
			q.push_back(a);
		}
	}

	return 0;
}