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
	for (int x = 0; x <= 500; x++) {
		for (int y = 0; y < x; y++) {
			for (int z = 0; z < y; z++) {
				if (x >= a and y >= b and z >= c and z >= d) {
					if (x <= 2*a and y <= 2*b and z <= 2*c) {
						if (2*d >= z && 2*d < y && 2*d < x) {
							printf("%d %d %d\n", x, y, z);
							return 0;
						}
					}
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}