#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[105];
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int dist = 0, ans = INT_MAX;
	for (int i = m+1; i < n; i++) {
		dist += 10;
		if (v[i] <= k && v[i] != 0) {
			ans = dist;
			break;
		}
	}

	dist = 0;

	for (int i = m-1; i >= 0; i--) {
		dist += 10;
		if (v[i] <= k && v[i] != 0) {
			ans = min(ans, dist);
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}