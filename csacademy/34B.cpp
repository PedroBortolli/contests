#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[1005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int price = v[i];
		ll cur = 0;
		for (int j = 0; j < n; j++) {
			if (v[j] >= price) cur += (ll)price;
		}
		ans = max(ans, cur);
	}

	printf("%lld\n", ans);
	return 0;
}