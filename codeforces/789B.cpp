#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <ll> s;
int main() {
	ll b, q, l, m, x;
	scanf("%lld %lld %lld %lld", &b, &q, &l, &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &x);
		s.insert(x);
	}

	if (b == 0) {
		if (s.find(b) == s.end()) {
			printf("inf\n");
			return 0;
		}
		else {
			printf("0\n");
			return 0;
		}
	}

	ll ans = 0;
	if (q == 0) {
		if (b > l or -1ll*b > l) {
			printf("0\n");
			return 0;
		}
		if (b <= l and -1ll*b <= l) {
			if (s.find(b) == s.end()) ans = 1ll;
		}
		b *= q;
		if (s.find(b) == s.end()) {
			printf("inf\n");
			return 0;
		}
		printf("%lld\n", ans);
		return 0;
	}

	if (q == 1ll) {
		if (b <= l and -1ll*b <= l) {
			if (s.find(b) == s.end())
				printf("inf\n");
			else printf("0\n");
			return 0;
		}
		else {
			printf("0\n");
			return 0;
		}
	}

	if (q == -1ll) {
		if (abs(b) > l or abs(b) > l) {
			printf("0\n");
			return 0;
		}
		else {
			if (s.find(b) == s.end()) {
				printf("inf\n");
				return 0;
			}
			else {
				b *= -1ll;
				if (s.find(b) == s.end()) {
					printf("inf\n");
					return 0;
				}
			}
		}
		printf("0\n");
		return 0;
	}

	while (1) {
		if (b > l) break;
		if (-1ll*b > l) break;
		if (s.find(b) == s.end()) ans++;
		b *= q;
	}

	printf("%lld\n", ans);

	return 0;
}