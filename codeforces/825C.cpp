#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[1111];
int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	sort(v, v+n);

	ll best = 2ll*k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] <= best) {
			best = max(best, v[i]*2);
		}
		else {
			while (v[i] > best) {
				ans++;
				best *= 2;
			}
			best = max(best, v[i]*2ll);
		}
	}

	printf("%d\n", ans);
	return 0;
}