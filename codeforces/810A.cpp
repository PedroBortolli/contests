#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	double n, k, x;
	scanf("%lf %lf", &n, &k);
	double tot = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &x);
		tot += x;
	}

	double med = tot/n;

	int ans = 0;
	while (1) {
		if (med + 0.5 >= k) break;
		else ans++;
		tot += k;
		med = tot/(n+ans);
	}

	printf("%d\n", ans);
	return 0;
}