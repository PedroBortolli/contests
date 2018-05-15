#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
#define int long long


int v[2005];
main() {
	int n, g;
	scanf("%lld", &n);

	int ok = 0, um = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		if (v[i] == 1) um++;
	}

	if (um) {
		printf("%lld\n", n-um);
		return 0;
	}

	int prev = v[0];
	for (int i = 1; i < n; i++) {
		g = __gcd(v[i], prev);
		prev = g;
	}

	if (g != 1) {
		printf("-1\n");
		return 0;
	}

	ok = 1;
	for (int i = 0; i < n-1 && ok; i++) {
		g = __gcd(v[i], v[i+1]);
		if (g == 1) ok = 0;
	}

	printf("%lld\n", n+ok-um);
	return 0;
}