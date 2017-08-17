#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[1111], l[1111], r[1111];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}


	int x = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		x += v[i];
		int ok = 0;
		int mn = INT_MAX;
		for (int j = 0; j < m; j++) {
			if (r[j] >= x) {
				ok = 1;
				if (l[j] > x) {
					mn = min(l[j]-x, mn);
				}
				else mn = 0;
			}
		}
		if (!ok) {
			printf("-1\n");
			return 0;
		}
		ans = (x+mn);
	}

	printf("%d\n", ans);
	return 0;
}