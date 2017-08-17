#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int aa[111], bb[111];
int main() {
	int n, a, b, ans = 0;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &aa[i], &bb[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int x = aa[i];
			int y = bb[i];
			int X = aa[j];
			int Y = bb[j];
			for (int k = 0; k < 2; k++) {
				swap(x,y);
				if (x <= a && y <= b) {
					for (int kk = 0; kk < 2; kk++) {
						swap(X,Y);
						int leftx = a;
						int lefty = b-y;
						if (X <= leftx && Y <= lefty) ans = max(ans, x*y+X*Y);
						leftx = a-x;
						lefty = b;
						if (X <= leftx && Y <= lefty) ans = max(ans, x*y+X*Y);
					}
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}