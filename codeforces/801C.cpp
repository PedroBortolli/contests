#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

double a[100005], b[100005], ha[100005], hb[100005];
double lim = 0.00001;
int main() {
	double n, p;
	scanf("%lf %lf", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &a[i], &b[i]);

	double l = 0.0, r = 1e13, m;

	for (int j = 0; j < 100; j++) {
		m = (l+r)/2.0;
		//printf("m = %lf\n", m);
		for (int i = 0; i < n; i++) {
			ha[i] = a[i];
			hb[i] = b[i];
		}

		double x = 0.0;
		for (int i = 0; i < n; i++) {
			b[i] -= m*a[i];
		}

		for (int i = 0; i < n; i++) {
			//printf("%lf ", b[i]);
			if (b[i] < 0.0) {
				//printf("%lf\n", (b[i]*-1.0)/(double)p);
				x += ((b[i]*-1.0)/(double)p);
			}
		}

		//printf("\nx = %lf\n", x);
		
		if (x > m) r = m;
		else l = m;

		for (int i = 0; i < n; i++) {
			a[i] = ha[i];
			b[i] = hb[i];
		}
	}

	if (l <= 1e12) printf("%.6lf\n", l);
	else printf("-1\n");
	return 0;
}