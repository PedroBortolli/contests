#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[105];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	int prev = 0;
	for (int i = 1; i <= n; i++) {
		int cand = v[i]+prev;
		if (cand > 8) {
			prev = cand-8;
			cand = 8;
		}
		else prev = 0;
		k -= cand;
		if (k <= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}