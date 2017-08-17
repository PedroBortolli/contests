#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v+n);
	ll ans = 0;

	for (int i = 1; i < n; i++) {
		if ((v[i]-v[0])%k != 0) {
			printf("-1\n");
			return 0;
		}
		ans += (ll(v[i]-v[0])/(ll)k);
	}

	printf("%lld\n", ans);
	return 0;
}