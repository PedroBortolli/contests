#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pii v[200005];
int d[200005];
int main() {
	int n, k, s, t, c, f;
	scanf("%d %d %d %d", &n, &k, &s, &t);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &f);
		v[i] = mp(c, f);
	}

	sort(v, v+n);

	for (int i = 0; i < k; i++)
		scanf("%d", &d[i]);
	sort(d, d+k);
	d[k] = s;

	int l = 0, r = 1000500000, m, ans = INT_MAX;
	while (l <= r) {
		m = (l+r)/2;
		int ok = 1, prev = 0, x = 0, tt = 0;
		for (int i = 0; i <= k; i++) {
			int dist = d[i]-prev;
			if (dist > m) {
				ok = 0;
				break;
			}
			else x = min(dist, m-dist);
			tt += (x+(dist-x)*2);
			prev = d[i];
		}

		if (tt > t) ok = 0;
		if (ok) r = m-1;
		else l = m+1;
	}

	for (int i = 0; i < n; i++) {
		if (v[i].second < l) continue;
		ans = min(ans, v[i].first);
	}

	if (ans == INT_MAX) ans = -1;
	printf("%d\n", ans);
	return 0;
}