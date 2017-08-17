#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	double n, k;
	scanf("%lf %lf", &n, &k);

	double l = 0, r = n, m;
	double c = 0, d = 0, ansc = 0, ansd = 0;
	for (int i = 0; i < 100; i++) {
		m = floor((l+r)/2.0);
		c = m;
		d = c*k;
		//printf("c = %.0lf  d = %.0lf\n", c, d);
		if (c+d > floor(n/2.0)) r = m-1;
		else {
			ansc = max(ansc, c);
			ansd = max(ansd, d);
			l = m+1;
		}
	}

	printf("%.0lf %.0lf %.0lf\n", ansc, ansd, n-ansc-ansd);
	return 0;
}