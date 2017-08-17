#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pii v[105];
int main() {
	int n, s, x, y;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v[i] = mp(x, y);
	}

	sort(v, v+n);

	int prev = s;
	int ans = 0;

	for (int i = n-1; i >= 0; i--) {
		ans += (prev-v[i].first);
		if (ans < v[i].second) {
			x = v[i].second-ans;
			ans += x;
		}
		prev = v[i].first;
	}

	printf("%d\n", ans+prev);
	return 0;
}