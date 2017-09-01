#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	double r, d, n, x, y, rr;
	int ans = 0;
	scanf("%lf %lf", &r, &d);
	scanf("%lf", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf", &x, &y, &rr);
		double dist = sqrt(x*x+y*y);
		if (dist-rr >= r-d && dist+rr <= r) ans++;
		
	}
	printf("%d\n", ans);
	return 0;
}	