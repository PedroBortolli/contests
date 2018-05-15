#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[200005];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	if (k == 0) {
		if (v[0] != 1) printf("1\n");
		else printf("-1\n");
		return 0;
	}
	if (k > n) {
		printf("-1\n");
		return 0;
	}
	if (k == n) {
		printf("%d\n", v[n-1]);
		return 0;
	}
	if (v[k-1] == v[k]) {
		printf("-1\n");
	}
	else printf("%d\n", v[k-1]);
	return 0;
}