#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, t, x;
	scanf("%d", &n);
	int ans = 0;
	int prev = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t, &x);
		if (t == 1) {
			if (prev == -1) prev = x;
		}
		else {
			if (prev == -1) continue;
			ans += (x-prev);
			prev = -1;
		}
	}
	printf("%d\n", ans);
	return 0;
}