#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, x, c0 = 0, c1 = 0, ok = 0, free = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			c0++;
			if (!ok) free++;
		}
		else {
			c1++;
			ok = 1;
		}
 	}
 	printf("%d\n", max(c0, c1+free));
	return 0;
}