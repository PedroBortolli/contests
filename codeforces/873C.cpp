#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, m, k, v[105][105];

int check(int i, int j) {
	int mn = min(k, n-i), cont = 0, aux = 0;
	for (int z = i; z < n; z++) {
		if (z == n) break;
		aux++;
		if (v[z][j]) cont++;
		if (aux == k) break;
	}
	return cont;
}

int main() {
	int ans1 = 0, ans2 = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	for (int j = 0; j < m; j++) {
		int best = 0, ch = 0, aux = 0;
		for (int i = 0; i < n; i++) {
			int x = v[i][j];
			if (x == 0) continue;
			int y = check(i, j);
			if (y > best) {
				best = y;
				ch = aux;
			}
			aux++;
		}
		ans1 += best;
		ans2 += ch;
	}

	printf("%d %d\n", ans1, ans2);
	return 0;
}