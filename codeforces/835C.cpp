#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


ll dp[111][111][15], sumx[111][111][15];
int main() {
	int n, q, c, x, y, s, t, xi, yi, Xi, Yi;
	scanf("%d %d %d", &n, &q, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &s);
		for (int k = 0; k <= c; k++) {
			int aux = (k+s)%(c+1);
			dp[x][y][k] += aux;
		}
	}

	for (int k = 0; k <= c; k++) {
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				sumx[i][j][k] = sumx[i-1][j][k] + dp[i][j][k];
			}
		}
	}

	while (q--) {
		scanf("%d %d %d %d %d", &t, &xi, &yi, &Xi, &Yi);
		t = t%(c+1);
		ll ans = 0;
		for (int j = yi; j <= Yi; j++) {
			//printf("Somando sum[%d][%d][%d] = %lld -   sum[%d][%d][%d] = %lld\n", Xi, j, t, sumx[Xi][j][t], xi-1, j, t, sumx[xi-1][j][t]);
			ans += (sumx[Xi][j][t]-sumx[xi-1][j][t]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}