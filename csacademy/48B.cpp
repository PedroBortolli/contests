#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int x[1005], y[1005];
int main() {
	int n;
	scanf("%d", &n);
	int cur = 0, aux = 0, ans = 0;
	int l = 0, r = 1000000, m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	int best = 0, worst = 0;
	for (int i = 0; i < n; i++) {
		if (x[i]) cur += y[i];
		else cur -= y[i];
		best = max(best, cur);
		worst = min(worst, cur);
	}

	printf("%d\n", best-worst);
	return 0;
}