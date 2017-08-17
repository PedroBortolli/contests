#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[200005], range[200005], r[200005], l[200005], a[200005];
pair <ll, ll> ord[200005];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &v[i]);

	sort(v+1, v+n+1);

	for (int i = 0; i < q; i++) {
		scanf("%lld %lld", &l[i], &r[i]);
		range[l[i]]++;
		range[r[i]+1]--;
	}

	ord[1] = mp(range[1], 1ll);
	for (int i = 2; i <= n; i++) {
		range[i] += range[i-1];
		ord[i] = mp(range[i], i);
	}

	sort(ord+1, ord+n+1);

	for (int i = n; i >= 1; i--) {
		int id = ord[i].second;
		a[id] = v[i];
	}

	for (int i = 2; i <= n; i++)
		a[i] += a[i-1];
		

	ll ans = 0;
	for (int i = 0; i < q; i++) {
		ans += (a[r[i]]-a[l[i]-1]);
	}

	printf("%lld\n", ans);
	return 0;
}