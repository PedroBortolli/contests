#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int has[200005], sum1[200005], sum2[200005], v[200005];

int main() {
	int n, k, q, l, r;
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &l, &r);
		has[l]++;
		has[r+1]--;
	}

	for (int i = 1; i <= 200000; i++) {
		sum1[i] = has[i] + sum1[i-1];
	}


	for (int i = 1; i <= 200000; i++) {
		if (sum1[i] >= k) v[i] = 1;
	}

	for (int i = 1; i <= 200000; i++) {
		sum2[i] = v[i] + sum2[i-1];
	}

	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", sum2[r]-sum2[l-1]);
	}

	return 0;
}