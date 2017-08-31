#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <int, pii> mp;
set <int> s;
int main() {
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (x == y) mp[x].first++;
		else {
			mp[x].first++;
			mp[y].second++;
		}
		s.insert(x);
		s.insert(y);
	}
	int ans = INT_MAX;
	for (auto a : s) {
		if (mp[a].first + mp[a].second >= n/2 + n%2) {
			ans = min(ans, max(n/2 + n%2 -mp[a].first, 0));
		}
	}
	if (ans == INT_MAX) ans = -1;
	printf("%d\n", ans);
}