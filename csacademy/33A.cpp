#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, x, y;
	scanf("%d", &n);
	int y1 = INT_MAX;
	int y2 = 0;
	int x1 = y1;
	int x2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		x1 = min(x1, x);
		x2 = max(x2, x);
		y1 = min(y1, y);
		y2 = max(y2, y);
	}

	printf("%d\n", (x2-x1)*(y2-y1));
	return 0;
}