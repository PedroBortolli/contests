#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pair <double, double> v[100005];
pair <double, double> vv[100005];
const double inf = 1e50;
const double eps = 0.00001;
int main() {
	int n;
	double a, b, l, r, m, x1, y1, x2, y2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a, &b);
		b *= -1;
		v[i] = mp(a,-b);
		vv[i] = mp(a, b);
	}
	sort(v, v+n);
	sort(vv, vv+n);
	
	l = -inf, r = inf;
	for (int i = 0; i < 1000; i++) {
		m = (l+r)/2.0;
		a = v[0].first;
		b = -v[0].second;
		double prev = a*m+b;
		double preva = a;
		int ok = 0;
		for (int j = 1; j < n; j++) {
			a = v[j].first;
			b = -v[j].second;
			double next = a*m+b;
			//printf("a = %lf     preva = %lf\n", a, preva);
			if (next >= prev && abs(a-preva) > eps) {
				ok = 1;
				break;
			}
			if (next < prev) {
				prev = next;
				preva = a;
			}
		}
		if (ok) {
			//printf("			deu bom\n");
			x1 = m;
			r = m;
		}
		else l = m;
	}
	
	l = -inf, r = inf;
	for (int i = 0; i < 1000; i++) {
		m = (l+r)/2.0;
		a = vv[0].first;
		b = vv[0].second;
		double prev = a*m+b;
		double preva = a;
		int ok = 0;
		for (int j = 1; j < n; j++) {
			a = vv[j].first;
			b = vv[j].second;
			double next = a*m+b;
			if (prev >= next && abs(a-preva) > eps) {
				ok = 1;
				break;
			}
			if (next > prev) {
				prev = next;
				preva = a;
			}
		}
		if (ok) {
			x2 = m;
			l = m;
		}
		else r = m;
	}

	printf("x1 = %.10lf       x2 = %.10lf\n", x1, x2);
	return 0;

	for (int i = 0; i < 1000; i++) {
		m = (l+r)/2.0;
		a = v[i].first;
		b = v[i].second;
		double prev = 0;
		for (int j = 1; j < n; j++) {

		}
	}
}