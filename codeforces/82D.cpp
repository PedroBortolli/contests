#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int dp[1005][1005];
pair <pii, pii> to[1005][1005];
int n, v[1005], seen[1005], aux[3];

void build(int alone, int group) {
	aux[0] = v[alone];
	aux[1] = v[group];
	aux[2] = v[group+1];
}

int go(int alone, int group, int used) {
	build(alone, group);
	sort(aux, aux+3);
	if (used == n-2) return max(aux[1], aux[2]);
	if (used == n-1) return aux[2];
	if (dp[alone][group] != -1) return dp[alone][group];

	int ans = INT_MAX;
	build (alone, group);
	if (max(aux[0], aux[1]) + go(group+1, group+2, used+2) < ans) {
		build (alone, group);
		ans = max(aux[0], aux[1]) + go(group+1, group+2, used+2);
		to[alone][group] = mp(mp(alone, group), mp(group+1, group+2));
	}
	
	build (alone, group);
	if (max(aux[0], aux[2]) + go(group, group+2, used+2) < ans) {
		build (alone, group);
		ans = max(aux[0], aux[2]) + go(group, group+2, used+2);
		to[alone][group] = mp(mp(alone, group+1), mp(group, group+2));
	}
	
	build (alone, group);
	if (max(aux[1], aux[2]) + go(alone, group+2, used+2) < ans) {
		build (alone, group);
		ans = max(aux[1], aux[2]) + go(alone, group+2, used+2);
		to[alone][group] = mp(mp(group, group+1), mp(alone, group+2));
	}
	
	return dp[alone][group] = ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	memset(dp, -1, sizeof(dp));
	memset(to, -1, sizeof(to));
	printf("%d\n", go(0, 1, 0));

	int x = 0, y = 1, nx, ny, k = 0;
	if (n%2 == 0) k = 1;
	for (int i = 0; i < n/2-k; i++) {
		int nx = to[x][y].first.first;
		int ny = to[x][y].first.second;
		printf("%d %d\n", nx+1, ny+1);
		seen[nx+1] = 1;
		seen[ny+1] = 1;
		nx = to[x][y].second.first;
		ny = to[x][y].second.second;
		x = nx;
		y = ny;
	}

	for (int i = 1; i <= n; i++) {
		if (!seen[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}