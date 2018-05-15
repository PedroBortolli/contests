#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> s[4005];
pii v[4005];
int main() {
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
		s[v[i].first].insert(v[i].second);
		s[v[i].second].insert(v[i].first);
	}

	int ans = INT_MAX;
	for (int i = 0; i < m; i++) {
		x = v[i].first;
		y = v[i].second;
		for (int j = 1; j <= n; j++) {
			if (j == x or j == y) continue;
			if (s[x].find(j) != s[x].end() && s[y].find(j) != s[y].end()) {
				ans = min(ans, (int)s[x].size()+(int)s[y].size()+(int)s[j].size()-6);
			}
		}
	}

	if (ans == INT_MAX) ans = -1;
	printf("%d\n", ans);
	return 0;
}