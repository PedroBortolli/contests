#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 3e5+5;
int l[N], r[N];
pii inp[N];

int main() {
	int n, k, x, y;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		inp[i] = {x,y};
	}
	sort(inp, inp+n);

	int ll = 0, rr = 2e9+1, m, ok = 0;
	while (ll <= rr) {
		m = (ll+rr)/2;
		ok = 0;
		for (int i = 0; i < n; i++) {
			l[i] = inp[i].first;
			r[i] = inp[i].second - m;
		}
		dequeue <pii> q;
		q.push_back({l[0], r[0]});
		for (int i = 1; i < n; i++) {
			if (q.size() == k) {
				ok = 1;
				break;
			}
			if (r[i] < l[i]) continue;
			while (!q.empty() && l[i] > q.front().r[i]) q.pop_front();
			q.push({l[i], r[i]});
		}
		if (ok) {
			ans = max(ans, m);
			ll = m+1;
		}
		else rr = m-1;
	}

	printf("%d\n", m);
	return 0;
}