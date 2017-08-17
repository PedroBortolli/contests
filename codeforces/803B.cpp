#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[200005], dist[200005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		dist[i] = INT_MAX;
	}

	int zero = -1;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) zero = i;
		if (zero == -1) continue;
		dist[i] = i-zero;
	}

	zero = -1;
	for (int i = n-1; i >= 0; i--) {
		if (v[i] == 0) zero = i;
		if (zero == -1) continue;
		dist[i] = min(dist[i], zero-i);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");

	return 0;
}