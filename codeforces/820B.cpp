#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	double n, aa;
	scanf("%lf %lf", &n, &aa);
	double ang = 180.0*(n-2.0)/n;
	double cons = (180.0-ang)/2.0;
	double a = ang, b = cons, c = cons;

	double ans = fabs(aa-a);
	int ans1 = 2, ans2 = 1, ans3 = n;
	if (fabs(aa-b) < ans) {
		ans1 = 1, ans2 = 2;
		ans = fabs(aa-b);
	}
	for (int i = 2; i <= n-2; i++) {
		a = fabs(ang-b);
		b = 180.0 - a - c;
		if (fabs(aa-a) < ans) {
			ans1 = i+1, ans2 = i;
			ans = fabs(aa-a);
		}
		if (fabs(aa-b) < ans) {
			ans1 = i, ans2 = i+1;
			ans = fabs(aa-b);
		}
	}

	printf("%d %d %d\n", ans1, ans2, ans3);
	return 0;
}