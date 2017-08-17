#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int xhi[100005], xlo[100005], yhi[100005], ylo[100005];
int sxhi[100005], sxlo[100005], syhi[100005], sylo[100005];
int main() {
	int k, n, m, a, b, c, d, cl, cr, ct, cb;
	scanf("%d", &k);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		xhi[i] = max(a, c);
		sxhi[xhi[i]]++;
		xlo[i] = min(a, c);
		sxlo[xlo[i]]++;
		yhi[i] = max(b, d);
		syhi[yhi[i]]++;
		ylo[i] = min(b, d);
		sylo[ylo[i]]++;
	}

	scanf("%d %d %d %d", &cl, &cr, &ct, &cb);

	for (int i = 2; i <= 100002; i++) {
		sxhi[i] += sxhi[i-1];
		sxlo[i] += sxlo[i-1];
		syhi[i] += syhi[i-1];
		sylo[i] += sylo[i-1];
	}


	for (int i = 0; i < k; i++) {
		a = sxlo[xhi[i]-1];
		if (xlo[i] < xhi[i]) a--;
		b = sxhi[100000]-sxhi[xlo[i]];
		if (xhi[i] > xlo[i]) b--;
		c = sylo[yhi[i]-1];
		if (ylo[i] < yhi[i]) c--;
		d = syhi[100000]-syhi[ylo[i]];
		if (yhi[i] > ylo[i]) d--;
		if (a == cl && b == cr && c == ct && d == cb) {
			printf("%d\n", i+1);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}