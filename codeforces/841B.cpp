#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll n, x, sum = 0, ok = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		if (x%2ll != 0) {
			ok = 1;
		}
	}

	if (!ok) printf("Second\n");
	else printf("First\n");
	return 0;
}