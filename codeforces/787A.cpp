#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int x, y;

	for (x = 0; x <= 5005; x++) {
		for (y = 0; y <= 5005; y++) {
			if (b+x*a == d+y*c) {
				printf("%d\n", b+x*a);
				return 0;
			}
		}
	}

	printf("-1\n");
	return 0;
}