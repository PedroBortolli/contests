#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char x[111], y[111], z[111];
int main() {
	scanf(" %s", x);
	scanf(" %s", y);

	int n = strlen(x);

	for (int i = 0; i < n; i++) {
		if (x[i] < y[i]) {
			printf("-1\n");
			return 0;
		}
	}

	printf("%s\n", y);
	return 0;
}