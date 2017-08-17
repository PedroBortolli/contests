#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pair <double, double> v1[100005], v2[100005], v3[100005], v4[100005];
const double inf = 1e50;
const double eps = 0.00001;

bool cmp1(const pii &a, const pii &b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

bool cmp2(const pair <double, double> &a, const pair <double, double> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

bool cmp3(const pair <double, double> &a, const pair <double, double> &b) {
	if (a.first == b.first)
		return a.second > b.second; //not sure??
	return a.first > b.first;
}

bool cmp4(const pair <double, double> &a, const pair <double, double> &b) {
	if (a.first == b.first)
		return a.second < b.second; //not sure??
	return a.first > b.first;
}

int main() {
	int n;
	double a, b, l, r, m, x1, y1, x2, y2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a, &b);
		b *= -1;
		v1[i] = mp(a,b);
		v2[i] = mp(a,b);
		v3[i] = mp(a,b);
		v4[i] = mp(a,b);
	}
	sort(v1, v1+n, cmp1);
	sort(v2, v2+n, cmp2);
	sort(v3, v3+n, cmp3);
	sort(v4, v4+n, cmp4);


	l = -inf, r = inf;
	for (int i = 0; i < 1000; i++) {
		m = (l+r)/2.0;
		a = v1[0].first;
		b = v1[0].second;
		double prev = a*m+b;
		double preva = a;
		int ok = 0;
		for (int j = 1; j < n; j++) {
			a = v1[j].first;
			b = v1[j].second;
			double next = a*m+b;
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
			x1 = m;
			r = m;
		}
		else l = m;
	}
	
	l = -inf, r = inf;
	for (int i = 0; i < 1000; i++) {
		m = (l+r)/2.0;
		a = v2[0].first;
		b = v2[0].second;
		double prev = a*m+b;
		double preva = a;
		int ok = 0;
		for (int j = 1; j < n; j++) {
			a = v2[j].first;
			b = v2[j].second;
			double next = a*m+b;
			printf("Esava em %.1lf e agora estou em %.1lf\n", prev, next);
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


	l = -inf, r = inf;
	for (int i = 0; i < 1000; i++) {
		m = (l+r)/2.0;
		a = v3[i].first;
		b = v3[i].second;
		double prev = (m-b)/a;
		double preva = a;
		int ok = 0;
		for (int j = 1; j < n; j++) {
			a = v3[j].first;
			b = v3[j].second;
			double next = (m-b)/a;
			if (prev <= next && abs(a-preva) > eps) {
				ok = 1;
				break;
			}
			if (next < prev) {
				prev = next;
				preva = a;
			}
		}
		if (ok) {
			y1 = m;
			l = m;
		}
		else r = m;
	}

	printf("x1 = %.10lf       x2 = %.10lf           y1 = %.10lf\n", x1, x2, y1);
	return 0;
}
